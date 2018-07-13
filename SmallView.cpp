//
// Created by Adam Stelmaszyk on 09.04.2018.
//

#include "SmallView.h"
#include <iostream>
#include <fstream>

using namespace sf;


void SmallView::run()
{

    if(!font.loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/arial.ttf"))
    {
        std::cout<<"Nie udalo sie wczytac czcionki"<<std::endl;
    }


    for(int i=0; i<Liczba; i++)
    {
        text[i].setFont(font);
    }
    text[0].setPosition(500,0);
    text[0].setString("Car game");

    text[1].setPosition(460, 60);
    text[1].setCharacterSize(20);
    text[1].setString("THE BEST SCORE:");

    text[2].setPosition(500, 300);
    text[2].setCharacterSize(20);
    text[2].setString("YOUR SCORE:");

    text[3].setPosition(550,330);
    text[3].setCharacterSize(50);

    text[4].setPosition(500,400);
    text[4].setCharacterSize(20);
    text[4].setString("YOUR LIFE:");


    text[5].setPosition(550,430);
    text[5].setCharacterSize(50);


    text[9].setPosition(500,90);
    text[9].setCharacterSize(20);
    text[9].setString("I POSITION:");

    text[6].setPosition(500,120);
    text[6].setCharacterSize(20);
    text[6].setFillColor(Color::Yellow);

    text[10].setPosition(500,150);
    text[10].setCharacterSize(20);
    text[10].setString("II POSITION:");

    text[7].setPosition(500,180);
    text[7].setCharacterSize(20);
    text[7].setFillColor(Color::Magenta);

    text[11].setPosition(500,210);
    text[11].setCharacterSize(20);
    text[11].setString("III POSITION:");

    text[8].setPosition(500,240);
    text[8].setCharacterSize(20);
    text[8].setFillColor(Color::Blue);


    OdczytZPliku();


}



void SmallView::draw(sf::RenderWindow &window)
{

    for(int i=0; i<Liczba; i++)
    {
        window.draw(text[i]);
    }
}

void SmallView::punkty(int punkt, int zycia)
{
    String punkt1= std::to_string(punkt);
    text[3].setString(punkt1);
    String zycia1= std::to_string(zycia);
    text[5].setString(zycia1);

}

void SmallView::OdczytZPliku()
{
    std::string linia[6];
    std::fstream plik;
    int i=6;
    int a=0;
    plik.open("/Users/adamstelmaszyk/CLionProjects/untitled2/text.txt",std::ios::in);
    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            plik>>linia[a];
            a++;
        }
        plik.close();
    }
    for(a=0; a<6; a=a+2)
    {
        text[i].setString(linia[a]+" "+linia[a+1]);
        i++;
    }
}