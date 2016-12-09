//
// Created by Randy Deng 12/9/16
//

#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.h"
#include "../CutScenes/Background.h"

#define MAX_NUM_ITEMS 4

class Instructions {
public :
    // constructor and destructors
    Instructions();
    ~Instructions();
    // functions
    void playInstructionsMusic();
    static int runInstructions(sf::RenderWindow &window);
private :
    int selectedItemIndex;
    sf::Font optionsFont;
    sf::Font titleFont;
    sf::Text instructions[MAX_NUM_ITEMS];

    sf::Music instructionsMusic;
};
