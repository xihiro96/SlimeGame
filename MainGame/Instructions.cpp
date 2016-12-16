//
// Created by Randy Deng 12/9/16
//

#include "Instructions.h"

Instructions::Instructions(float width, float height) {
    // CREATE TEXT HERE
    // Loop through text: set font, size, color
    float sp;
    for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        instructions[i].setFont(optionsFont);
        instructions[i].setColor(sf::Color::White);
        instructions[i].setCharacterSize(25);
    }
    // CONTROLS SECTION
    instructions[0].setFont(titleFont);
    instructions[0].setColor(sf::Color::Green);
    instructions[0].setString("Controls");
    instructions[0].setCharacterSize(50);
    instructions[0].setStyle(sf::Text::Bold);
    instructions[0].setPosition(width/10, height/(MAX_NUM_ITEMS +1) * 1.0f);
    // set controls position
    sp = 3.0f;
    for (int i = 1; i < 6; i++) {
        instructions[i].setPosition(width/10.0f, height/(MAX_NUM_ITEMS + 1) * sp);
        sp++;
    }
    instructions[1].setString("W - Jump");
    instructions[2].setString("A - Move Left");
    instructions[3].setString("D - Move Right");
    instructions[5].setString("Enter - Continue Dialog");

    // STORY SECTION
    instructions[6].setFont(titleFont);
    instructions[6].setColor(sf::Color::Green);
    instructions[6].setString("Story");
    instructions[6].setCharacterSize(50);
    instructions[6].setStyle(sf::Text::Bold);
    instructions[6].setPosition(width/1.7f, height/(MAX_NUM_ITEMS +1) * 1.1f);
    instructions[7].setString("Lost! Lost! LOST!");
    instructions[7].setPosition(width/1.7f, height/(MAX_NUM_ITEMS + 1) * 3.0f);
    // set text width apart
    sp = 5.0f;
    for (int i = 8; i < 15; i++) {
        instructions[i].setPosition(width/1.7f, height/(MAX_NUM_ITEMS + 1) * sp);
        sp++;
    }
    instructions[8].setString("Adventure through dangerous");
    instructions[9].setString("terrains and collect the");
    instructions[10].setString("ingredients necessary to");
    instructions[11].setString("become a human. But beware,");
    instructions[12].setString("danger lurks all around you.");
    instructions[13].setString("Will you be able to achieve");
    instructions[14].setString("your dreams? or die trying?");

    // RETURN SECTION
    instructions[15].setString("Press Enter to Return");
    instructions[15].setPosition(width/2.6f, height/(MAX_NUM_ITEMS + 1) * 14.0f);
}

void Instructions::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUM_ITEMS; i++) {
        window.draw(instructions[i]);
    }
}

void Instructions::runMenu(sf::RenderWindow &window) {
    // get screen size
    int screenX = window.getSize().x;
    int screenY = window.getSize().y;
    // create instance
    Instructions instr(screenX, screenY);
    // set background
    Background back;
    sf::RectangleShape backgroundIm = back.createBackground("forest.jpg", sf::Vector2f(screenX, screenY));
    // play music
    instr.playMenuMusic2();
    // fade in
    instr.fadeIn(window, instr, backgroundIm);
    // loop to check for key presses
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    // if return is pressed, return to main screen
                    if (event.key.code == sf::Keyboard::Return) {
                        // play sound, fade, leave screen
                        instr.playSelectSound();
                        instr.fadeOut(window);
                        return;
                    }
                }
            }
        // clear and update the screen
        instr.render(window, instr, backgroundIm);
        }
    }