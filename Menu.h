//
// Created by Adam Stelmaszyk on 31.03.2018.
//
#pragma  once

#include <SFML/Graphics.hpp>
#include "Numery.h"
#define MAX_NUMBERS 3

using namespace sf;
class Menu {
public:
    Menu(float width, float height, int * numer);
    ~Menu();


    void run();
    void processEvents();
    void update();
    void render();
    void MoveUp();
    void MoveDown();
    int GetPressedItem()
    { return selectedItemIndex; };

private:
    RenderWindow nWindow;
    sf::Text nameApp;
    sf::Texture takeMenu;
    sf::Sprite drawPhotoMenu;
    sf::Font font;
    sf::Text menu[MAX_NUMBERS];
    int *ref;
    int selectedItemIndex;





};

