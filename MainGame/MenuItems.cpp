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

// render screen
void MenuItems::render(sf::RenderWindow &window, MenuItems &menu, sf::RectangleShape &backgroundIm) {
    window.clear();
    window.draw(backgroundIm);
    menu.draw(window);
    window.display();
}

// fade in and fade out functions
void MenuItems::fadeIn(sf::RenderWindow &window, MenuItems &menu, sf::RectangleShape &backgroundIm) {
    sf::RectangleShape fade;
    fade.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    // fade in
    sf::Uint8 a = 255;
    // prevents white flash from occuring
    fade.setFillColor(sf::Color(0,0,0,255));
    window.draw(fade);
    window.display();
    // fade in by changing transparency
    while(a > 0) {
        a--;
        window.clear();
        window.draw(backgroundIm);
        menu.draw(window);
        window.draw(fade);
        fade.setFillColor(sf::Color(0,0,0,a));
        window.display();
    }
}
void MenuItems::fadeOut(sf::RenderWindow &window) {
    // create rectangle
    sf::RectangleShape fade;
    fade.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    // fade out
    sf::Uint8 a = 0;
    while(a < 255) {
        fade.setFillColor(sf::Color(0,0,0,a));
        a++;
        window.draw(fade);
        window.display();
    }
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