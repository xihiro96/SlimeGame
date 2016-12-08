//
// Created by marites on 11/14/16.
//

#include "AnimatedGameObject.h"
AnimatedGameObject::AnimatedGameObject() {

}
bool AnimatedGameObject::load(const std::string& filename) {
    if(m_texture.loadFromFile(filename)) {
        m_filename = filename;
        m_sprite.setTexture(m_texture);
        m_valid = true;
        return true;
    }
    return false;
}

void AnimatedGameObject::draw(sf::RenderWindow& window) {
    if(m_valid)
        window.draw(m_sprite);
}

void AnimatedGameObject::move(sf::Vector2f loc) {
    if(m_valid)
        m_sprite.move(loc);
}

void AnimatedGameObject::setPosition(float x, float y) {
    if(m_valid)
        m_sprite.setPosition(x, y);
}

sf::Vector2f AnimatedGameObject::getPosition() const {
    if(m_valid)
        return m_sprite.getPosition();
    else
        return sf::Vector2f(0, 0);
}

float AnimatedGameObject::getHeight() const {
    return m_sprite.getLocalBounds().height;
}

float AnimatedGameObject::getWidth() const {
    return m_sprite.getLocalBounds().width;
}

void AnimatedGameObject::setScale(float scale) {
    if(m_valid)
        m_sprite.setScale(scale, scale);
}

void AnimatedGameObject::setCrop(int x, int y, int width, int height) {
    m_rect_sprite.top = x;
    m_rect_sprite.left = y;
    m_rect_sprite.height = height;
    m_rect_sprite.width = width;

    m_sprite.setTextureRect(m_rect_sprite);
}

void AnimatedGameObject::update(int increment, int endVal) {
    if(clk.getElapsedTime().asSeconds() > .1f) {
        if(m_rect_sprite.left >= endVal) {
            m_rect_sprite.left = 0;
        }
        else {
            m_rect_sprite.left += increment;
        }
        m_sprite.setTextureRect(m_rect_sprite);
        clk.restart();
    }
}