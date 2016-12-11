//
// Created by Randy Deng 12/9/16
//

#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "AnimatedGameObject.h"

class Slime : public AnimatedGameObject {
public :
    // constructor/destructor
    Slime(int levelNum);
    ~Slime();
    // sound functions
    void playJumpSound();
    void playAttackSound();
    void playItemSound();
    void setAction(std::string);
    std::string getAction();
    void setDirection(int);
    int getDirection();

private :
    // sound variables
    sf::SoundBuffer bufferJump;
    sf::SoundBuffer bufferAttack;
    sf::SoundBuffer bufferItem;
    sf::Sound soundJump;
    sf::Sound soundAttack;
    sf::Sound soundItem;
    std::string Action;
    int Direction;
};
