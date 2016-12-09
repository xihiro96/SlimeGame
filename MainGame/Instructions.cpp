//
// Created by Randy Deng 12/9/16
//

#include "Instructions.h"

Instructions::Instructions() {
    // set music
    // background music sound
    if (!instructionsMusic.openFromFile("Silence-of-the-Forest.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
}

Instructions::~Instructions() {

}

void Instructions::playInstructionsMusic() {
    instructionsMusic.play();
}

int Instructions::runInstructions(sf::RenderWindow &window) {

}