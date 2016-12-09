//
// Created by Randy Deng 12/9/16
//

#include "Instructions.h"

Instructions::Instructions(float width, float height) {
    // set music
    // background music sound
    if (!instructionsMusic.openFromFile("Silence-of-the-Forest.ogg")){
        std::cout << "Error reading sound" << std::endl;
    }
    instructionsMusic.setLoop(true);
    // cursor selection sound
    if (!bufferSelect.loadFromFile("Kingdom_Hearts_Sound_EffectsSelect.wav")){
        std::cout << "Error reading sound" << std::endl;
    }

    // create the text
    if(!optionsFont.loadFromFile("bit.ttf")){
        //handle error
    }
    if(!titleFont.loadFromFile("Perfect DOS VGA 437.ttf")){
        //handle error
    }
    instructions[0].setFont(optionsFont);
    instructions[0].setFillColor(sf::Color::Green);
    instructions[0].setString("W - Jump");
    instructions[0].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 1.5f);
    instructions[0].setCharacterSize(40);

    instructions[1].setFont(optionsFont);
    instructions[1].setFillColor(sf::Color::White);
    instructions[1].setString("A - Move Left");
    instructions[1].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 2.5f);

    instructions[2].setFont(optionsFont);
    instructions[2].setFillColor(sf::Color::White);
    instructions[2].setString("F - Move Right");
    instructions[2].setPosition(width/1.3f, height/(MAX_NUM_ITEMS + 1) * 3.5f);

    instructions[3].setFont(titleFont);
    instructions[3].setFillColor(sf::Color::Green);
    instructions[3].setString("Instructions");
    instructions[3].setCharacterSize(75);
    instructions[3].setStyle(sf::Text::Bold);
    instructions[3].setPosition(width/10, height/(MAX_NUM_ITEMS +1) * .3f);
}

Instructions::~Instructions() {

}

void Instructions::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        window.draw(instructions[i]);
    }
}

void Instructions::playSelectSound() {
    soundSelect.setBuffer(bufferSelect);
    soundSelect.play();
}

void Instructions::playInstructionsMusic() {
    instructionsMusic.play();
}

void Instructions::runInstructions(sf::RenderWindow &window) {
    // create instance
    Instructions instr(window.getSize().x, window.getSize().y);
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("forest.jpg", sf::Vector2f(1280,720));
    // play music
    //instr.playInstructionsMusic();
    // loop to check for key presses
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyReleased:
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return ||
                            event.key.code == sf::Keyboard::BackSpace ||
                            event.key.code == sf::Keyboard::Escape) {
                        instr.playSelectSound();
                        // screen fade and return
                        sf::RectangleShape fade;
                        fade.setSize(sf::Vector2f(1280, 720));
                        int a = 0;
                        while(a < 255) {
                            fade.setFillColor(sf::Color(0,0,0,a));
                            a++;
                            window.draw(fade);
                            window.display();
                        }
                        return;
                    }
                }
            }
        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        instr.draw(window);
        window.display();
        }
    }