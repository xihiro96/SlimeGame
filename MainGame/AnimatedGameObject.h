//
// Created by marites on 11/14/16.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class AnimatedGameObject : public GameObject{
public:
    AnimatedGameObject();
    virtual bool load(const std::string& filename);

    virtual void draw(sf::RenderWindow& window);

    virtual void update(int increment, int endVal);

    virtual void setPosition(float x, float y);

    virtual void move(sf::Vector2f);

    virtual sf::Vector2f getPosition() const;

    virtual float getHeight() const;

    virtual float getWidth() const;

    virtual void setScale(float scale);

    virtual void setCrop(int x, int y, int width, int height);

private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::string m_filename;
    sf::IntRect m_rect_sprite;
    sf::Clock clk;
    bool m_valid = false;
};

