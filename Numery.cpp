//
// Created by Adam Stelmaszyk on 11.04.2018.
//

#include "Numery.h"
#include <iostream>
#include <fstream>
using namespace sf;

KoniecGry::KoniecGry(float t_X, float t_Y, int *numer, int *punkty): kWindow(VideoMode(t_X,t_Y),"CAR GAME")
{
    if(!font.loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/LemonMilk.otf"))
    {

    }

    takeBreakCar.loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/zbite.png");
    Sprite sprite(takeBreakCar);
    drawBreakCar=sprite;

    for(int i=0; i<MAX_NUMBERS; i++)
    {
        text[i].setFont(font);
    }

    refPunkty=punkty;
    liczba=*refPunkty;
    std::string punkt=std::to_string(liczba);
    text[0].setFillColor(sf::Color::Black);
    text[0].setString("GAME OVER");
    text[0].setCharacterSize(80);
    text[0].setPosition(sf::Vector2f(t_X/7,0));

    text[1].setPosition(sf::Vector2f(200,200));
    text[1].setString("Your SCORE:");
    text[1].setCharacterSize(40);
    text[1].setFillColor(sf::Color::Cyan);

    text[2].setPosition(sf::Vector2f(500, 200));
    text[2].setString(punkt);
    text[2].setCharacterSize(40);
    text[2].setFillColor(sf::Color::Cyan);

    text[3].setString("New Game");
    text[3].setCharacterSize(30);
    text[3].setPosition(sf::Vector2f(50,720));
    text[3].setFillColor(Color::Yellow);

    text[4].setString("Come Back to MENU");
    text[4].setCharacterSize(30);
    text[4].setPosition(sf::Vector2f(300,720));
    text[4].setFillColor(Color::Black);

    zmianawyniku[0].setFont(font);
    zmianawyniku[0].setString("!!! SUPER SCORE !!!");
    zmianawyniku[0].setCharacterSize(50);
    zmianawyniku[0].setPosition(sf::Vector2f(t_X/6,t_Y/(MAX_NUMBERS)*2));
    zmianawyniku[0].setFillColor(Color::Black);

    zmianawyniku[1].setFont(font);
    zmianawyniku[1].setString("Give me your nick: ");
    zmianawyniku[1].setCharacterSize(30);
    zmianawyniku[1].setPosition(sf::Vector2f(230,650));
    zmianawyniku[1].setFillColor(Color::Cyan);

    zmianawyniku[2].setFont(font);
    zmianawyniku[2].setCharacterSize(30);
    zmianawyniku[2].setPosition(sf::Vector2f(550,650));
    zmianawyniku[2].setFillColor(Color::Cyan);

    ref=numer;
    selectedItemIndex=3;
    OdczytPliku();

}

void KoniecGry::run()
{
    while(kWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }

}

void KoniecGry::processEvents()
{

    sf::Event event;
    while(kWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed ) {
            *ref=0;
            kWindow.close();
        }
        if(event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode == 0x08 && str.size() > 0)
            {
                str.erase(str.size() - 1, 1);
                zmianawyniku[2].setString(str);
            }

            else if (event.text.unicode < 128 && str.size() < 5 && event.text.unicode != 0x08)
            {
                str += static_cast<char>(event.text.unicode);
                zmianawyniku[2].setString(str);
            }
        }




        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code==sf::Keyboard::Left)
            {
                MoveUp();
            }
            if(event.key.code==sf::Keyboard::Right)
            {
                MoveDown();
            }
            if(event.key.code==sf::Keyboard::Return)
            {
                if(selectedItemIndex==3)
                {
                    *ref=2;
                    WczytaniedoPliku();
                    kWindow.close();
                }
                if(selectedItemIndex==4)
                {
                    *ref=1;
                    WczytaniedoPliku();
                    kWindow.close();
                }
            }
        }
    }
}

void KoniecGry::update() {}

void KoniecGry::render()
{
    kWindow.clear();
    kWindow.draw(drawBreakCar);
    for(int i=0; i<MAX_NUMBERS; i++)
    {
        kWindow.draw(text[i]);
    }
    if(liczba>liczby[2])
    {
        kWindow.draw(zmianawyniku[0]);
        kWindow.draw(zmianawyniku[1]);
        kWindow.draw(zmianawyniku[2]);
    }

    kWindow.display();
}

void KoniecGry::MoveUp()
{
    if(selectedItemIndex-1 >=3)
    {
        text[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex--;
        text[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}

void KoniecGry::MoveDown()
{
    if(selectedItemIndex+1 < 5)
    {
        text[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex++;
        text[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}



void KoniecGry::WczytaniedoPliku()
{
    int i=0;
    int a=0;
    int b=0;

    for(i=0; i<3; i++)
    {
        if(*refPunkty>liczby[i])
        {
            liczby[i]=*refPunkty;
            if(str=="")
            {
                str="UNKOWN";
            }
            nazwa[i]=str;
            //trzeba bedzie podac jeszcze imie

            plik.open("/Users/adamstelmaszyk/CLionProjects/untitled2/text.txt",std::ios::out);
            {
                for(a=0; a<3; a++)
                {
                    plik<<nazwa[a]<<" "<<liczby[a]<<" ";
                    plik.flush();
                }
            }
            plik.close();
            break;
        }
    }


}

void KoniecGry::OdczytPliku()
{
    std::string slowo;
    int i=0;
    int a=0;
    int b=0;

    plik.open("/Users/adamstelmaszyk/CLionProjects/untitled2/text.txt",std::ios::in);
    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            plik>>slowo;
            if((i%2)==1)
            {
                liczby[a]=stoi(slowo);
                a++;
            }
            else if((i%2)==0){
                nazwa[b]=slowo;
                b++;
            }
            i++;
        }
        plik.close();
    }
}