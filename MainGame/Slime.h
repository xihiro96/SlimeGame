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
    Slime();
    ~Slime();
    // sound functions
    void playJumpSound();
    void playAttackSound();
    void playItemSound();

private :
    // sound variables
    sf::SoundBuffer bufferJump;
    sf::SoundBuffer bufferAttack;
    sf::SoundBuffer bufferItem;
    sf::Sound soundJump;
    sf::Sound soundAttack;
    sf::Sound soundItem;
};
