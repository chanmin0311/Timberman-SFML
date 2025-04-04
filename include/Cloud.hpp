// Cloud.hpp
#pragma once
#include "../include/Entity.hpp"

class Cloud : public Entity {
   public:
    Cloud(float baseY = 0);
    void update(sf::Time dt) override;
    void render(sf::RenderWindow& window) override;

   private:
    sf::Texture mTexture;
    sf::Sprite mSprite;
    bool mActive;
    float mSpeed;
    float mBaseY;

    void reset();
};