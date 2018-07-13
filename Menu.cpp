//
// Created by Adam Stelmaszyk on 31.03.2018.
//

#include "Menu.h"
#include "WindowGame.h"
#include "Numery.h"

Menu::Menu(float width, float height, int * numer): nWindow(VideoMode(width,height),"CAR GAME")
{
    if(!font.loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/Heavy.ttf"))
    {

    }

    takeMenu.loadFromFile("/Users/adamstelmaszyk/CLionProjects/untitled2/menu_zdjecie.png");
    Sprite sprite(takeMenu);
    drawPhotoMenu=sprite;

    nameApp.setFont(font);
    nameApp.setFillColor(sf::Color::Yellow);
    nameApp.setString("CAR GAME");
    nameApp.setCharacterSize(40);
    nameApp.setPosition(sf::Vector2f(200,height/(MAX_NUMBERS+4)*1));


    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Yellow);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBERS+2)*2));
    menu[0].setStyle(sf::Text::Bold);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Instruction");
    menu[1].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBERS+2)*3));
    menu[1].setStyle(sf::Text::Bold);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("EXIT");
    menu[2].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBERS+2)*4));
    menu[2].setStyle(sf::Text::Bold);

    selectedItemIndex = 0;
    ref = numer;

}

Menu::~Menu() {}

void Menu::run()
{
    while(nWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Menu::processEvents()
{
    sf::Event event;
    while(nWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed ) {
            *ref=0;
            nWindow.close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code==Keyboard::Up)
            {
                MoveUp();
            }
            if(event.key.code==Keyboard::Down)
            {
                MoveDown();
            }
            if(event.key.code==Keyboard::Return)
            {
                if(selectedItemIndex==0)
                {
                    *ref=2;
                    nWindow.close();
                }
                if(selectedItemIndex==1)
                {
                    *ref=4;
                    nWindow.close();
                }
                if(selectedItemIndex==2)
                {
                    *ref=0;
                    nWindow.close();
                }
            }

        }
    }
}

void Menu::render()
{
    nWindow.draw(drawPhotoMenu);
    nWindow.draw(nameApp);
    for(int i=0; i<3; i++)
    {
        nWindow.draw(menu[i]);
    }
    nWindow.display();
}
void Menu::update() {}

void Menu::MoveUp()
{
    if(selectedItemIndex-1 >=0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}

void Menu::MoveDown()
{
    if(selectedItemIndex+1 < MAX_NUMBERS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}

