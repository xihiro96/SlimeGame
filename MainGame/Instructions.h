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
    Instructions(float width, float height);
    ~Instructions();
    // functions
    void draw(sf::RenderWindow &window);
    void playInstructionsMusic();
    void playSelectSound();
    static void runInstructions(sf::RenderWindow &window);
private :
    sf::Font optionsFont;
    sf::Font titleFont;
    sf::Text instructions[MAX_NUM_ITEMS];

    sf::SoundBuffer bufferSelect;
    sf::Sound soundSelect;
    sf::Music instructionsMusic;
};
