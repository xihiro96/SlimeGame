//
// Created by bswenson3 on 11/9/16.
//
#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "RegularGameObject.h"
#include "AnimatedGameObject.h"
#include <iostream>

class Game {
public:
    //use default screen size
    Game();
    sf::RenderWindow m_window;
    //run the game
    void run();

private:
    void processEvents();
    //update the game objects
    void update(sf::Time deltaT);
    //draw the scene
    void render();
    //handle input from the user
    void handlePlayerInput(sf::Keyboard::Key key, bool isDown);

    RegularGameObject m_player;

    //TODO::these should be moved to game object
    float m_speed = 120.0f;
    bool m_left = false;
    bool m_right = false;
    bool m_up = false;
    bool m_down = false;
};


