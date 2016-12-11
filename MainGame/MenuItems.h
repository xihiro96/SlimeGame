//
// Created by Randy Deng on 12/10/16.
//

/*
 * PARENT CLASS OF ALL MENU ITEMS INCLUDING: MainMenu, Instructions, GameOver, etc
 * Takes care of all the sounds used in the menu
 * Text is taken care of individually by each menuItem
 */

#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "../CutScenes/Background.h"

class MenuItems {
public :
    // constructor and destructor
    MenuItems();
    ~MenuItems();
    // play sound functions
    void playCursorSound();
    void playSelectSound();
    void playGameOverSound();
    void playMenuMusic();
    void playMenuMusic2();
protected :
    // include fonts
    sf::Font optionsFont;
    sf::Font titleFont;
private :
    // include sound variables
    sf::SoundBuffer bufferCursor;
    sf::SoundBuffer bufferSelect;
    sf::SoundBuffer bufferGameOver;
    sf::Sound soundCursor;
    sf::Sound soundSelect;
    sf::Sound soundGameOver;
    sf::Music menuMusic;
    sf::Music menuMusic2;
};