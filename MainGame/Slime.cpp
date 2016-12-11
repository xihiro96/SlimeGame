//
// Created by Randy Deng on 12/9/16
//

#include "Slime.h"

Slime::Slime(int levelNum) {
    // load slime sprite
    // dependant on levelNum (or element type)
    //TODO make class that stores slime health, enemy health, slime element
    //object pickup
    std::string slimeType;
    switch(levelNum){
        case 1: slimeType = "plainSlime.png";
            break;
        case 2: slimeType = "forestSlime.png";
            break;
        case 3: slimeType = "waterSlime.png";
            break;
        case 4: slimeType = "caveSlime.png";
            break;
        case 5: slimeType = "fireSlime.png";
            break;
    }
    this -> load(slimeType);
    // crop slime sprite
    this -> setCrop(0, 96, 32, 32);
    // resize slime
    this -> setScale(4.0f);
    // position slime
    this -> setPosition(0, 500);

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
void Slime::setAction(std::string _Action){
    Action = _Action;
}

std::string Slime::getAction(){
    return Action;
}

void Slime::setDirection(int _Direction){
    Direction = _Direction;
}

int Slime::getDirection(){
    return Direction;
}