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
    void render(sf::RenderWindow& window, sf::RectangleShape& background, Slime& player, StageLevel& level);
    // level music
    void playLevelMusic();
    // boundary checking
    void smartMove(Slime &player, sf::RenderWindow &window, sf::Vector2f &movement, float m_speed, bool direction);
    bool checkCollisions(Slime &player, int &plat);
    void checkGround(Slime &player);
    // check win and dead condition
    int checkWinDead(Slime &player);

private :
    // create the game objects
    std::vector<GameObject*> gameObjects;
    RegularGameObject plat1;
    RegularGameObject plat2;
    RegularGameObject plat3;
    RegularGameObject plat4;
    RegularGameObject plat5;
    RegularGameObject plat6;
    RegularGameObject plat7;
    RegularGameObject plat8;
    // gameObject positions
    std::vector<int> xPos;
    std::vector<int> yPos;
    // winning condition
    RegularGameObject winItem;
    int winx;
    int winy;
    // sound variables
    sf::Music levelMusic;
};