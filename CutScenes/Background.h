//
// Created by marites on 12/6/16.
//

#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Background {
public:
    Background();

    sf::RectangleShape createBackground(std::string fileName, sf::Vector2f resolution);

    void setBack(int backNum);//setter

    const std::string& getBack(); //getter

private:
    sf::Texture texture;
    std::string currentBack;
};


