//
// Created by Randy Deng on 12/10/16.
//

#include "MenuItems.h"

// constructor and destructor
MenuItems::MenuItems() {
    // set all sounds/music
    // cursor movement sound
    if (!bufferCursor.loadFromFile("Kingdom_Hearts_Sound_EffectsCursor_Move.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // cursor selection sound
    if (!bufferSelect.loadFromFile("Kingdom_Hearts_Sound_EffectsSelect.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // game over sound
    if (!bufferGameOver.loadFromFile("game_over.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    // background music for MainMenu
    if (!menuMusic.openFromFile("Silence-of-the-Forest.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
    menuMusic.setLoop(true);
    // background music for Instructions
    if (!menuMusic2.openFromFile("quiet_slumber_instr.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    menuMusic2.setLoop(true);

    // set game text fonts
    if(!optionsFont.loadFromFile("bit.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
    if(!titleFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        std::cout << "Error. Could not read font file" << std::endl;
    }
}
MenuItems::~MenuItems() {

}

// play sound functions
void MenuItems::playCursorSound() {
    soundCursor.setBuffer(bufferCursor);
    soundCursor.play();
}
void MenuItems::playSelectSound() {
    soundSelect.setBuffer(bufferSelect);
    soundSelect.play();
}
void MenuItems::playGameOverSound() {
    soundGameOver.setBuffer(bufferGameOver);
    soundGameOver.play();
}
void MenuItems::playMenuMusic() {
    menuMusic.play();
}
void MenuItems::playMenuMusic2() {
    menuMusic2.play();
}