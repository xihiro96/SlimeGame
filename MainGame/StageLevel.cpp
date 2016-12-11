//
// Created by Randy Deng on 12/8/16.
//

#include "StageLevel.h"

StageLevel::StageLevel() {
    // create the sounds once
    // background music sound
    if (!levelMusic.openFromFile("trap_queen_8bit_lv1.wav")){
        std::cout << "Error reading sound" << std::endl;
    }
    levelMusic.setLoop(true);
    // add gameObjects to vector

}

StageLevel::~StageLevel() {

}

void StageLevel::draw(sf::RenderWindow &window) {
    //for (int i = 0; i < gameObjects.size(); i++) {
    //    gameObjects[i] -> draw(window);
    //}
}

void StageLevel::playLevelMusic() {
    levelMusic.play();
}

int StageLevel::runLevel(sf::RenderWindow &window, int levelNum) {
    // set main menu screen and background
    StageLevel level;
    Background back;
    back.setBack(levelNum);
    sf::RectangleShape backgroundIm = back.createBackground(back.getBack(), sf::Vector2f(window.getSize().x, window.getSize().y));
    // play music
    level.playLevelMusic();
    // set m_speed and slime
    float m_speed = 300.0f;
    Slime player(levelNum);
    sf::Clock clock;

    // read key presses
    while(window.isOpen()) {
        // set up events and clocks
        sf::Time deltaT = clock.restart();
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                // read which key was released (up/down)
                case sf::Event::KeyPressed :
                    sf::Vector2f movement(0.0f, 0.0f);
                    switch (event.key.code)
                    {
                        // slime jump
                        case sf::Keyboard::W :
                            player.playJumpSound();
                            break;
                        // slime move left
                        case sf::Keyboard::A :
                            movement.x -= m_speed;
                            player.move(movement * deltaT.asSeconds());
                            break;
                        // slime move right
                        case sf::Keyboard::D :
                            movement.x += m_speed;
                            player.move(movement * deltaT.asSeconds());
                            break;
                        // slime attack
                        case sf::Keyboard::Space :
                            player.playAttackSound();
                            break;
                        // backspace to pause game
                        case sf::Keyboard::Return:
                            break;
                    }
            }
        }
        //player.update(32, 32*10);
        // clear and update the screen
        window.clear();
        window.draw(backgroundIm);
        // update slime
        player.draw(window);
        player.update(32, 32*9);
        level.draw(window);
        window.display();
    }
}