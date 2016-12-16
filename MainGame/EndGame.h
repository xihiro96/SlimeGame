//
// Created by Randy Deng 12/9/16
//

#pragma once

#include "MenuItems.h"

class EndGame : public MenuItems{
public :
    // constructor/destructor
    EndGame(float width, float height, double score);
    // display gameOver screen
    void draw(sf::RenderWindow &window);
    static void runMenu(sf::RenderWindow &window, double score);
private :
    // text
    static const int MAX_NUM_ITEMS = 2;
    sf::Text gameOverText[MAX_NUM_ITEMS];
};
