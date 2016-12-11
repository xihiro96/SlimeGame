//
// Created by Randy Deng 12/9/16
//

#pragma once

#include "MenuItems.h"

class GameOver : public MenuItems{
public :
    // constructor/destructor
    GameOver(float width, float height);
    // display gameOver screen
    void draw(sf::RenderWindow &window);
    static void runMenu(sf::RenderWindow &window);
private :
    // text
    static const int MAX_NUM_ITEMS = 2;
    sf::Text gameOverText[MAX_NUM_ITEMS];
};
