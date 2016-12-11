//
// Created by marites on 12/3/16.
//

#pragma once

#include "MenuItems.h"

class MainMenu : public MenuItems{
public:
    MainMenu(float width, float height);

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem() {return selectedItemIndex;}
    static int runMenu(sf::RenderWindow &window);

private:
    int selectedItemIndex;
    static const int MAX_NUM_ITEMS = 4;
    sf::Text menu[MAX_NUM_ITEMS];
};

