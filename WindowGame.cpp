//
// Created by Adam Stelmaszyk on 08.04.2018.
//

#include "WindowGame.h"
#include <fstream>
#include "Dziura.h"
#include "samochod.h"
#include <iostream>


using namespace sf;

WindowGame::WindowGame(float t_X, float t_Y, int * numer,int *punkty) : mWindow(VideoMode(t_X,t_Y),"CAR GAME")
{
    takeRoad.loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/road.png");

    samochod.date(370,600, "/Users/adamstelmaszyk/CLionProjects/untitled2/czarnysam.png");
    dziura[0].date(20,-82, "/Users/adamstelmaszyk/CLionProjects/untitled2/bariera.png");
    dziura[3].date(125, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/bariera.png");
    dziura[6].date(245, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/bariera.png");
    dziura[9].date(350, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/bariera.png");
    dziura[1].date(20, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    dziura[4].date(125, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    dziura[7].date(245, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    dziura[10].date(350, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    dziura[2].date(20, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");
    dziura[5].date(125, -82,"/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");
    dziura[8].date(245, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");
    dziura[11].date(350, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");
    dziura[12].date(20,-82, "/Users/adamstelmaszyk/CLionProjects/untitled2/zepsuty.png");
    dziura[15].date(125, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/zepsuty.png");
    dziura[18].date(245, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/zepsuty.png");
    dziura[21].date(350, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/zepsuty.png");
    dziura[13].date(20, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    dziura[16].date(125, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    dziura[19].date(245, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    dziura[22].date(350, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    dziura[14].date(20, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");
    dziura[17].date(125, -82,"/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");
    dziura[20].date(245, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");
    dziura[23].date(350, -82, "/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");


    Sprite sprite(takeRoad);
    drawRoad=sprite;
    mWindow.setFramerateLimit(90);
    this->t_Y=t_Y;
    Zycia=3;
    timeGolwny[1]=0;
    timeGolwny[2]=0;
    Punkty=0;
    iloscnieaktywnych=0;
    CzasDoPunktow=0;
    smallView.run();
    ref = numer;
    refpunkty = punkty;
    clock.restart();
}

template <class T1, class T2> bool isIntersecting(T1 & A, T2 & B)
{
    //zamiast wszytskich funkcji
    return A.right() >= B.left() && A.left() <=B.right()
           && A.bottom() >= B.top() && A.top() <= B.bottom();

};

void WindowGame::run()
{
    while(mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void WindowGame::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            *ref=0;
            mWindow.close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code==Keyboard::Left)
            {
                samochod.updatePositionLeft();
            }
            if(event.key.code==Keyboard::Right)
            {
                samochod.updatePositionRight();
            }
            if(event.key.code==Keyboard::Up)
            {
                samochod.updatePositionTop();
            }
            if(event.key.code==Keyboard::Down)
            {
                samochod.updatePositionDown();
            }
        }
    }
}

void WindowGame::update()
{

    LiczeniePunktow();
    smallView.punkty(Punkty, Zycia);
    for(int i=0; i<LiczbaDziur; i++)
    {
        dziura[i].updatePosition(level);
        colision(samochod,dziura[i]);
    }
    losowaniePrzeszkody();
    gdzieSa();
    Koniecgry();


}

void WindowGame::render()
{
    mWindow.clear();
    mWindow.draw(drawRoad);
    for(int i=0; i<LiczbaDziur; i++)
    {
        dziura[i].draw(mWindow);
    }
    samochod.draw(mWindow);
    smallView.draw(mWindow);
    mWindow.display();
}

int WindowGame::LiczeniePunktow()
{

    int czas=clock.getElapsedTime().asSeconds();
    if(czas<=30)
    {
        level=1;
        speed=200;
        if(czas!=CzasDoPunktow)
        {
            Punkty = Punkty + 1;
            //std::cout<<Punkty<<std::endl;
            CzasDoPunktow=czas;
        }
    }
    else if(30<czas && czas<=60)
    {
        level=1.20;
        speed=100;
        if(czas!=CzasDoPunktow)
        {
            Punkty = Punkty + 2;
            //std::cout<<Punkty<<std::endl;
            CzasDoPunktow=czas;
        }
    }
    else if(60<czas && czas<=100)
    {
        level=1.40;
        speed=50;
        if(czas!=CzasDoPunktow)
        {
            Punkty = Punkty + 3;
            //std::cout<<Punkty<<std::endl;
            CzasDoPunktow=czas;
        }
    }
    else if(100<czas && czas<=140)
    {
        level=1.50;
        speed=25;
        if(czas!=CzasDoPunktow)
        {
            Punkty = Punkty + 4;
            //std::cout<<Punkty<<std::endl;
            CzasDoPunktow=czas;
        }
    }
    else if(140<czas)
    {
        level=2.30;
        speed=2;
        if(czas!=CzasDoPunktow)
        {
            Punkty = Punkty + 5;
            //std::cout<<Punkty<<std::endl;
            CzasDoPunktow=czas;
        }

    }
}

bool WindowGame::colision(Samochod & colsamochod, Dziura & przeszkoda)
{
    if(!isIntersecting(colsamochod,przeszkoda))
        return false;

    przeszkoda.updatePositiontop();
    Zycia=Zycia-1;

    return true;

}

void WindowGame::losowaniePrzeszkody()
{

    srand(time(NULL));
    int time1 = clock.getElapsedTime().asMilliseconds();

    if((time1%speed)==0 && timeGolwny[1]!=time1)
    {

        if (iloscnieaktywnych > 0) {

            int liczba = (rand() % LiczbaDziur);


            if (liczba < LiczbaDziur) {
                if(!(dziura[liczba].getPositionY() < 800 && dziura[liczba].getPositionY() > -82)) {
                    dziura[liczba].changePosition();
                }


            }
        }
        timeGolwny[1]=time1;
    }
    if((time1%15)==0 && timeGolwny[2]!=time1 &&  time1>200000 )
    {
        if (iloscnieaktywnych > 0) {

            int liczba = (rand() % LiczbaDziur);

            liczba=liczba+1;

            if (liczba < LiczbaDziur) {
                if(!(dziura[liczba].getPositionY() < 800 && dziura[liczba].getPositionY() > -82)) {
                    dziura[liczba].changePosition();
                }


            }
        }
        timeGolwny[2]=time1;
    }


}

void WindowGame::gdzieSa()
{
    iloscnieaktywnych=0;
    for(int i=0; i<LiczbaDziur; i++)
    {
        if (!(dziura[i].getPositionY() < 800 && dziura[i].getPositionY() > -82)) {
            iloscnieaktywnych=iloscnieaktywnych+1;
        }
    }


}

void WindowGame::Koniecgry()
{
    if(Zycia<=0)
    {
        *refpunkty=Punkty;
        *ref=3;
        mWindow.close();

    }
}


