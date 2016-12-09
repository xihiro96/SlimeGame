//
// Created by Randy Deng on 12/8/16.
//

#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.h"
#include "../CutScenes/Background.h"
#include "Slime.h"
#include "RegularGameObject.h"

class StageLevel {
public :
    // Constructor/Destructor
    StageLevel(float width, float height);
    ~StageLevel();
    // run the level function
    static int runLevel(sf::RenderWindow &window);
    // draw
    void draw(sf::RenderWindow &window);
    // level music
    void playLevelMusic();

private :
    // create the game objects
    std::vector<GameObject*> gameObjects;
    // sound variables
    sf::Music levelMusic;
};