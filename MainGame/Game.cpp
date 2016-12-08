//
// Created by bswenson3 on 11/9/16.
//

#include "Game.h"

Game::Game() :
    m_window(sf::VideoMode(640, 480), "Cool Game")
{
    //load the player
    m_player.load("Mario.png");

    //size him.  trial and error to get correct values
    m_player.setScale(.1f);


}

void Game::run() {
    sf::Clock clock;

    while(m_window.isOpen()) {
        sf::Time deltaT = clock.restart();
        processEvents();
        update(deltaT);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
            //handle key down here
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
    if(key == sf::Keyboard::Left)
        m_left = isDown;
    if(key == sf::Keyboard::Right)
        m_right = isDown;
    if(key == sf::Keyboard::Up)
        m_up = isDown;
    if(key == sf::Keyboard::Down)
        m_down = isDown;
}

//use time since last update to get smooth movement
void Game::update(sf::Time deltaT) {
    //Look a vector class!
    sf::Vector2f movement(0.0f, 0.0f);
    if(m_up)
        movement.y -= m_speed;
    if(m_down)
        movement.y += m_speed;
    if(m_left)
        movement.x -= m_speed;
    if(m_right)
        movement.x += m_speed;

    m_player.move(movement * deltaT.asSeconds());

}

void Game::render() {
    m_window.clear();
    m_player.draw(m_window);
    m_window.display();
}