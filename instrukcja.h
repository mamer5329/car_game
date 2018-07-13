//
// Created by Adam Stelmaszyk on 12.04.2018.
//

#pragma once

#include <SFML/Graphics.hpp>

const int Liczba_Tekstu=13;
const int Liczba_Font=2;

class Instrukcja {
public:
    Instrukcja(float t_X, float t_Y, int * numer);
    ~Instrukcja()= default;
    void run();
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow iWindow;
    sf::Text text[Liczba_Tekstu];
    sf::Font font[Liczba_Font];
    sf::Texture takePhoto[5];
    sf::Sprite drawPhoto[5];
    int *ref;



};

