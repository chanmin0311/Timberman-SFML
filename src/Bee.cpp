// Bee.cpp
#include "../include/Bee.hpp"
#include <random>

Bee::Bee() : mActive(false), mSpeed(0.0f) {
    mTexture.loadFromFile("../assets/images/bee.png");
    mSprite.setTexture(mTexture);
    mSprite.setPosition(1980, 800);
}

void Bee::reset() {
    // Create random_device to get seed value
    std::random_device rd;
    // Initialize our random number generator
    std::mt19937 gen(rd());
    // Define unifrom distributions
    std::uniform_int_distribution<int> speed_dist(0, 200);
    std::uniform_int_distribution<int> alt_dist(0, 500);

    // Set bee's attributes
    mSpeed = speed_dist(gen) + 200;
    float altitude = alt_dist(gen) + 300;
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