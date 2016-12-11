//
// Created by Randy Deng on 12/8/16.
//

#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "../CutScenes/Background.h"
#include "Slime.h"
#include "RegularGameObject.h"

class StageLevel {
public :
    // Constructor/Destructor
    StageLevel(int levelNum);
    ~StageLevel();
    // run the level function
    static int runLevel(sf::RenderWindow &window, int levelNum);
    // draw
    void draw(sf::RenderWindow &window);
    // level music
    void playLevelMusic();

private :
    // create the game objects
    std::vector<GameObject*> gameObjects;
    // sound variables
    sf::Music levelMusic;
    // set background
    sf::RectangleShape backgroundIm;
};