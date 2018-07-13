//
// Created by Adam Stelmaszyk on 08.04.2018.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Dziura.h"
#include "samochod.h"
#include <iostream>
#include "SmallView.h"

const int LiczbaDziur=24;

class WindowGame {
public:
    WindowGame(float t_X, float t_Y, int * numer, int *punkty);
    void run();

private:
    void processEvents();
    void update();
    void render();
    bool colision(Samochod & colsamochod, Dziura & przeszkoda);
    void losowaniePrzeszkody();
    void gdzieSa();
    void Koniecgry();
    int LiczeniePunktow();


private:
    sf::RenderWindow mWindow;
    sf::Texture takeRoad;
    sf::Sprite drawRoad;
    sf::Clock clock;
    SmallView smallView;
    Samochod samochod;
    Dziura dziura[LiczbaDziur];
    float t_Y;
    int Zycia;
    int timeGolwny[2];
    int speed;
    int iloscnieaktywnych;
    float level;
    int Punkty;
    int CzasDoPunktow;
    int *ref;
    int *refpunkty;





};


