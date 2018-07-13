//
// Created by Adam Stelmaszyk on 01.04.2018.
//

#include "Dziura.h"
#include <iostream>
using namespace sf;

Dziura::Dziura() {}

void Dziura::date(float t_X, float t_Y, std::string file)
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

void Dziura::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Dziura::updatePosition(float liczba)
{
    if(sprite.getPosition().y<800.25 && sprite.getPosition().y>-82)
    {
        sprite.setPosition(Vector2f(t_X, sprite.getPosition().y + liczba));
    }

}

void Dziura::updatePositiontop()
{
        sprite.setPosition(Vector2f(t_X, sprite.getPosition().y - 500));

}


float Dziura::top()
{
    return this->sprite.getPosition().y - sprite.getScale().y/2.f;
}
float Dziura::bottom()
{
    return this->sprite.getPosition().y + sprite.getScale().y/2.f;
}

float Dziura::left()
{
    return this->sprite.getPosition().x - sprite.getScale().x/2.f;
}

float Dziura::right()
{
    return this->sprite.getPosition().x +sprite.getScale().x/2.f;
}

float Dziura::getPositionY()
{
    return this->sprite.getPosition().y;
}

void Dziura::changePosition()
{
    sprite.setPosition(Vector2f(this->t_X,(this->t_Y+1)));
}