// Entity.hpp
#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class Entity {
   public:
    virtual void update(sf::Time dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual ~Entity() = default;

    int rand_int_uniform_dist(int min, int max) {
        // Create a uniform distribution between min and max
        std::uniform_int_distribution<int> dist(min, max);
        // Generate a random number using the distribution
        return dist(gen);
    }

   private:
    // Random number generator
    // This will be used to generate random numbers for the entities
    std::random_device rd;
    // Mersenne Twister random number generator
    // This is a high-quality random number generator
    std::mt19937 gen{rd()};
};

#endif  // ENTITY_HPP