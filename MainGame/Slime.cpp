//
// Created by Randy Deng on 12/9/16
//

#include "Slime.h"

Slime::Slime() {
    // load slime sprite
    this -> load("slime_sprites.png");
    // crop slime sprite
    this -> setCrop(0, 96, 32, 32);
    // resize slime
    this -> setScale(4.0f);
    // position slime
    this -> setPosition(0, 400);

    // jump sound
    if (!bufferJump.loadFromFile("jump.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // attack sound
    if (!bufferAttack.loadFromFile("attack.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // picking up item sound
    if (!bufferItem.loadFromFile("get_item.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
}

Slime::~Slime() {

}

void Slime::playJumpSound() {
    soundJump.setBuffer(bufferJump);
    soundJump.play();
}
void Slime::playAttackSound() {
    soundAttack.setBuffer(bufferAttack);
    soundAttack.play();
}
void Slime::playItemSound() {
    soundItem.setBuffer(bufferItem);
    soundItem.play();
}