// Bee.cpp
#include "../include/Bee.hpp"
#include <random>

Bee::Bee() : mActive(false), mSpeed(0.0f) {
    mTexture.loadFromFile("../assets/images/bee.png");
    mSprite.setTexture(mTexture);
    mSprite.setPosition(1980, 800);
}

void Bee::reset() {
    auto beeSpeed = rand_int_uniform_dist(0, 200);
    auto beeAltitude = rand_int_uniform_dist(0, 500);

    // Set bee's attributes
    mSpeed = beeSpeed + 200;
    float altitude = beeAltitude + 300;
    mSprite.setPosition(1980, altitude);
    mActive = true;
}

void Bee::update(sf::Time dt) {
    if (!mActive) {
        reset();
    } else {
        mSprite.move(-mSpeed * dt.asSeconds(), 0);
        if (mSprite.getPosition().x < -100) {
            mActive = false;
        }
    }
}

void Bee::render(sf::RenderWindow& window) {
    if (mActive) window.draw(mSprite);
}

int Bee::rand_int_uniform_dist(int min, int max) {
    // Define unifrom distributions
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}