//
// Created by Randy Deng on 12/8/16.
//

#include "StageLevel.h"

StageLevel::StageLevel(int levelNum) {
    // set background music depending on level
    switch(levelNum) {
        case 1 :
            if (!levelMusic.openFromFile("trap_queen_8bit_lv1.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            break;
        case 2 :
            if (!levelMusic.openFromFile("panda_8bit_lv2.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            break;
        case 3 :
            if (!levelMusic.openFromFile("radioactive_8bit_lv3.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            break;
        case 4 :
            if (!levelMusic.openFromFile("heathens_8bit_lv4.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            break;
        case 5 :
            if (!levelMusic.openFromFile("sao_8bit_lv5.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
            break;
        default :
            if (!levelMusic.openFromFile("trap_queen_8bit_lv1.wav")){
                std::cout << "Error reading sound" << std::endl;
            }
    }
    levelMusic.setLoop(true);
}

StageLevel::~StageLevel() {

}

void StageLevel::smartMove(Slime &player, sf::RenderWindow &window, sf::Vector2f &movement, float m_speed, sf::Time deltaT, bool direction) {
    sf::Vector2f temp = player.getPosition();
    // check for window collision

    while(player.getPosition().x > window.getSize().x - 90 || player.getPosition().x < - 40) {
        while(player.getPosition().x > window.getSize().x - 90) {
            movement.x -= m_speed;
            player.move(movement * deltaT.asSeconds());
        }
        while(player.getPosition().x < -40) {
            movement.x += m_speed;
            player.move(movement * deltaT.asSeconds());
        }
    }
    // move normally
    if (direction) {
        movement.x += m_speed;
        player.move(movement * deltaT.asSeconds());
    } else {
        movement.x -= m_speed;
        player.move(movement * deltaT.asSeconds());
    }
}

void StageLevel::checkCollisions() {

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
    StageLevel level(levelNum);
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
                    if (event.key.code == sf::Keyboard::W) {
                        player.playJumpSound();
                    }
                    if (event.key.code == sf::Keyboard::A) {
                        level.smartMove(player, window, movement, m_speed, deltaT, false);
                    }
                    if (event.key.code == sf::Keyboard::D) {
                        level.smartMove(player, window, movement, m_speed, deltaT, true);
                    }
                    if (event.key.code == sf::Keyboard::Space) {
                        player.playAttackSound();
                    }
            }
        }
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