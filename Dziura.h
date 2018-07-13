//
// Created by Adam Stelmaszyk on 01.04.2018.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Dziura{
public:
    Dziura();
    ~Dziura() = default;
    void date(float t_X, float t_Y, std::string file);
    void draw(sf::RenderWindow &window);
    void updatePosition(float liczba);
    void updatePositiontop();
    float getPositionY();
    void changePosition();
    Sprite sprite;

    float left();
    float right();
    float top();
    float bottom();


private:
    sf::Texture texture;

    float t_X;
    float t_Y;



};

