//
// Created by marites on 12/3/16.
//

#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "../CutScenes/Background.h"

#define MAX_NUM_ITEMS 4

class MainMenu {
public:
    MainMenu(float width, float height);
    ~MainMenu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem() {return selectedItemIndex;}
    void playCursorSound();
    void playSelectSound();
    void playMenuMusic();
    static int runMenu(sf::RenderWindow &window);

private:
    int selectedItemIndex;
    sf::Font optionsFont;
    sf::Font titleFont;
    sf::Text menu[MAX_NUM_ITEMS];
    sf::SoundBuffer bufferCursor;
    sf::SoundBuffer bufferSelect;
    sf::Sound soundCursor;
    sf::Sound soundSelect;

    sf::Music menuMusic;
};

