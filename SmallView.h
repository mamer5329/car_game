//
// Created by Adam Stelmaszyk on 09.04.2018.
//

#pragma once

#include <SFML/Graphics.hpp>

const int Liczba=12;

class SmallView {
public:
    SmallView()= default;
    ~SmallView() = default;
    void run();
    void OdczytZPliku();
    void punkty(int punkt, int zycia);
    void draw(sf::RenderWindow &window);
    sf::Font font;
    sf::Text text[Liczba];






};

