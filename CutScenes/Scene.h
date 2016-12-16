//
// Created by marites on 12/12/16.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "../MainGame/MenuItems.h"
#include "../MainGame/AnimatedGameObject.h"
#include <iostream>
class Scene : public MenuItems{
public :
    // constructor/destructor
    Scene(float width, float height);
    // display gameOver screen
    void draw(sf::RenderWindow &window);
    static void runScene1(sf::RenderWindow &window);
    static void runScene2(sf::RenderWindow &window);
    static void runScene3(sf::RenderWindow &window);
    static void runScene4(sf::RenderWindow &window);
    static void runScene5(sf::RenderWindow &window);
    static void runScene6(sf::RenderWindow &window);
    static void runScene7(sf::RenderWindow &window);
    static void runScene8(sf::RenderWindow &window);
    static void runScene9(sf::RenderWindow &window);
    static void runScene10(sf::RenderWindow &window);
    static void runScene11(sf::RenderWindow &window);
    std::vector<std::string> createStrings(std::string line);
private :
    // text

    static const int MAX_NUM_ITEMS = 2;
    sf::Text scene1Text[MAX_NUM_ITEMS];
};



