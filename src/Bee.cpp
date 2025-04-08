// Bee.cpp
#include "../include/Bee.hpp"
#include <random>

Bee::Bee() : mActive(false), mSpeed(0.0f) {
    // Bee path to read and load the bee texture
    std::string beePath = "../assets/images/bee.png";
    if (!mTexture.loadFromFile(beePath)) {
        throw std::runtime_error("Failed to load bee texture");
    }
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