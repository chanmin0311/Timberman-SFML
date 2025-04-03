// Entity.cpp
#include "../include/Entity.hpp"

#include <iostream>

Entity::Entity(const std::string& texturePath, float x, float y) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Failed to load texture: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Entity::setPosition(float x, float y) { sprite.setPosition(x, y); }

void Entity::draw(sf::RenderWindow& window) { window.draw(sprite); }