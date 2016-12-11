//
// Created by marites on 12/6/16.
//

#include "Background.h"
#include <iostream>

Background::Background() {

}

// sets background for levels
void Background::setBack(int backNum){
    switch(backNum){
        case 1: currentBack = "Plains_back.jpg";
            break;
        case 2: currentBack = "forest_back.png";
            break;
        case 3: currentBack = "ocean_back.jpg";
            break;
        case 4: currentBack = "cave_back.png";
            break;
        case 5: currentBack = "volcano_back.png";
            break;
    }
}

const std::string& Background::getBack(){
    return currentBack;
}

sf::RectangleShape Background::createBackground(std::string fileName, sf::Vector2f resolution) {
    sf::RectangleShape rect(resolution);
    if (!texture.loadFromFile(fileName)) {
        std::cout << "ERROR ERROR" << std::endl;
    }
    rect.setTexture(&texture);
    return rect;
}