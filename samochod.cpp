//
// Created by Adam Stelmaszyk on 08.04.2018.
//

#include "Samochod.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Samochod::Samochod()
{

}

void Samochod::date(float t_X, float t_Y, std::string file)
{
    if(!texture.loadFromFile(file))
    {
        std::cout<<"Nie udalo sie"<<std::endl;
    }

    this->t_X=t_X;
    this->t_Y=t_Y;
    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(this->t_X,this->t_Y));
}


void Samochod::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Samochod::updatePositionRight()
{
    if((sprite.getPosition().x)<340)
    {
        sprite.setPosition(Vector2f(sprite.getPosition().x + 110, sprite.getPosition().y));
    }
}

void Samochod::updatePositionLeft()
{
    if(sprite.getPosition().x>40)
    {
        sprite.setPosition(Vector2f(sprite.getPosition().x - 110, sprite.getPosition().y));
    }
}

void Samochod::updatePositionTop()
{
    if((sprite.getPosition().y)>300)
    {
        sprite.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y-50));
    }
}
void Samochod::updatePositionDown()
{
    if((sprite.getPosition().y)<599)
    {
        sprite.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y+50));
    }
}


float Samochod::top()
{
    return this->sprite.getPosition().y - 100/2;
}

float Samochod::bottom()
{
    return this->sprite.getPosition().y + 100/2;
}

float Samochod::right()
{
    return this->sprite.getPosition().x + 50/2;
}

float Samochod::left()
{
    return this->sprite.getPosition().x - 50/2;
}