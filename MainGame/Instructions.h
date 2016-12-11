//
// Created by Randy Deng 12/9/16
//

#pragma once

#include "MenuItems.h"

class Instructions : public MenuItems{
public :
    // constructor and destructors
    Instructions(float width, float height);
    // functions
    void draw(sf::RenderWindow &window);
    static void runMenu(sf::RenderWindow &window);
private :
    static const int MAX_NUM_ITEMS = 16;
    sf::Text instructions[MAX_NUM_ITEMS];
};
