//
// Created by Randy Deng 12/9/16
//

#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

#define MAX_NUM_ITEMS 2

class GameOver {
public :
    // constructor/destructor
    GameOver(float width, float height);
    ~GameOver();
    // music/sounds
    void playSelectSound();
    void playGameOverSound();
    // display gameOver screen
    void draw(sf::RenderWindow &window);
    static void runGameOver(sf::RenderWindow &window);
private :
    // game over sound
    sf::SoundBuffer gameOverBuffer;
    sf::SoundBuffer bufferSelect;
    sf::Sound soundGameOver;
    sf::Sound soundSelect;
    // display text
    sf::Font titleFont;
    sf::Font optionsFont;
    sf::Text gameOverText[MAX_NUM_ITEMS];
};
