//
// Created by Adam Stelmaszyk on 12.04.2018.
//

#include "instrukcja.h"

using namespace sf;

Instrukcja::Instrukcja(float t_X, float t_Y, int * numer) : iWindow(VideoMode(t_X,t_Y),"CAR GAME")
{
    ref=numer;


    if(!font[0].loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/LemonMilk.otf"))
    {
    }
    if(!font[1].loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/arial.ttf"))
    {
    }

    takePhoto[0].loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/zepsuty.png");
    takePhoto[1].loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/roboty.png");
    takePhoto[2].loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/znak.png");
    takePhoto[3].loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/klawisze.png");
    takePhoto[4].loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/strzalka.png");
    for(int i=0; i<5; i++)
    {
        Sprite sprite(takePhoto[i]);
        drawPhoto[i]=sprite;
    }

    for(int i=1; i<Liczba_Tekstu; i++)
    {
        text[i].setFont(font[1]);
    }
    text[0].setFont(font[0]);
    text[0].setString("Here is your GUIDE for the game");
    text[0].setPosition(100,0);

    text[1].setString("Be careful if you see those signs: ");
    text[1].setPosition(10,70);
    text[1].setCharacterSize(20);

    text[2].setString("Use only left, right,  ");
    text[2].setPosition(370,70);
    text[2].setCharacterSize(20);

    text[12].setString("up and down buttons:");
    text[12].setPosition(370,90);
    text[12].setCharacterSize(20);
    text[12].setFillColor(Color::White);

    text[3].setString("The goal in the game: ");
    text[3].setPosition(250,250);
    text[3].setCharacterSize(20);

    text[4].setString("YOU HAVE TO BE THE BEST AMONG THE PLAYERS");
    text[4].setPosition(80,280);
    text[4].setCharacterSize(20);

    text[5].setString("SHORT ABOUT INVENTOR OF THE GAME:");
    text[5].setPosition(10,450);
    text[5].setCharacterSize(30);
    text[5].setFillColor(Color::Yellow);

    text[6].setString("- I am from Poznan");
    text[6].setPosition(10,500);
    text[6].setCharacterSize(20);
    text[6].setFillColor(Color::Yellow);

    text[7].setString("- I am studying on the best technical university in the world(Poznan)");
    text[7].setPosition(10,530);
    text[7].setCharacterSize(20);
    text[7].setFillColor(Color::Yellow);

    text[8].setString("- I like programing app on android ");
    text[8].setPosition(10,560);
    text[8].setCharacterSize(20);
    text[8].setFillColor(Color::Yellow);

    text[9].setString("Phone contact: 123456789  ");
    text[9].setPosition(10,680);
    text[9].setCharacterSize(20);
    text[9].setFillColor(Color::White);

    text[10].setString("E-mail contact: comapny@comapny.pl ");
    text[10].setPosition(10,720);
    text[10].setCharacterSize(20);
    text[10].setFillColor(Color::White);

    text[11].setString("Poznan 63-000 ul.Kazimierza Wielkiego 23 ");
    text[11].setPosition(10,760);
    text[11].setCharacterSize(20);
    text[11].setFillColor(Color::White);

    drawPhoto[0].setPosition(10,120);
    drawPhoto[1].setPosition(100,100);
    drawPhoto[2].setPosition(200,100);
    drawPhoto[3].setPosition(400,80);
    drawPhoto[4].setPosition(20,300);


}

void Instrukcja::run()
{
    while(iWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Instrukcja::processEvents()
{
    sf::Event event;
    while(iWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            iWindow.close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code==Keyboard::Left)
            {
                *ref=1;
                iWindow.close();
            }
        }
    }
}

void Instrukcja::update()
{

}

void Instrukcja::render()
{
    iWindow.clear();

    for(int i=0; i<5; i++)
    {
        iWindow.draw(drawPhoto[i]);
    }
    for(int i=0; i<Liczba_Tekstu; i++)
    {
        iWindow.draw(text[i]);
    }
    iWindow.display();
}