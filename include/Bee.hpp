// Bee.hpp
#pragma once
#include "Entity.hpp"

class Bee : public Entity {
    public: 
    Bee();
    void update(sf::Time dt) override;
    void render(sf::RenderWindow& window) override;

    private:
    sf::Texture mTexture;
    sf::Sprite mSprite;
    bool mActive;
    float mSpeed;

    void reset();
};