//
// Created by Adam Stelmaszyk on 11.04.2018.
//


#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
const int MAX_NUMBERS=6;

class KoniecGry {
public:
    KoniecGry(float t_X, float t_Y, int * numer,int *punkty);
    ~KoniecGry()= default;
    void run();
    void processEvents();
    void update();
    void render();
    void MoveUp();
    void MoveDown();
    void WczytaniedoPliku();
    void OdczytPliku();



private:
    int liczba;
    int liczby[3];
    int selectedItemIndex;
    int *ref;
    int *refPunkty;
    std::fstream plik;
    std::string nazwa[3];
    sf::Texture takeBreakCar;
    sf::Sprite drawBreakCar;
    sf::RenderWindow kWindow;
    std::string str="";
    sf::Font font;
    sf::Text nameApp;
    sf::Text text[MAX_NUMBERS];
    sf::Text zmianawyniku[3];

};



