//
// Created by Adam Stelmaszyk on 08.04.2018.
//

#pragma once

#include "Dziura.h"

class Samochod  {

public:
    Samochod();
    ~Samochod()= default;
    void draw(sf::RenderWindow &window);
    void date(float t_X, float t_Y, std::string file);
    void updatePositionRight();
    void updatePositionLeft();
    void updatePositionTop();
    void updatePositionDown();


    float left();
    float right();
    float top();
    float bottom();

private:

    float t_X;
    float t_Y;
    sf::Texture texture;
    Sprite sprite;
};


