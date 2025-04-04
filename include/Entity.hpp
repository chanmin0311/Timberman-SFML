// Entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#pragma once
#include <SFML/Graphics.hpp>

class Entity {
   public:
    virtual void update(sf::Time dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual ~Entity() = default;
};

#endif  // ENTITY_HPP