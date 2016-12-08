//
// Created by marites on 12/6/16.
//

#include "Background.h"
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>

Background::Background() {

}
sf::RectangleShape Background::createBackground(std::string fileName, sf::Vector2f resolution) {
    sf::RectangleShape rect(resolution);
    if (!texture.loadFromFile(fileName)) {
        std::cout << "ERROR ERROR" << std::endl;
    }
    rect.setTexture(&texture);
    return rect;
}