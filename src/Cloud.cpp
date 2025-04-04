// Cloud.cpp
#include "../include/Cloud.hpp"

#include <random>

Cloud::Cloud(float baseY) : mActive(false), mSpeed(0.0f), mBaseY(baseY) {
    mTexture.loadFromFile("../assets/images/cloud.png");
    mSprite.setTexture(mTexture);
    mSprite.setPosition(-200, baseY);
}

void Cloud::reset() {
    // Create random_device to get seed value
    std::random_device rd;
    // Initialize our random number generator
    std::mt19937 gen(rd());
    // Define unifrom distributions
    std::uniform_int_distribution<int> speed_dist(50, 200);
    std::uniform_int_distribution<int> alt_dist(0, 150);

    // Set cloud's attribures
    mSpeed = speed_dist(gen);
    float altitude = alt_dist(gen) - 150 + mBaseY;
    mSprite.setPosition(-200, altitude);
    mActive = true;
}

void Cloud::update(sf::Time dt) {
    if (!mActive) {
        reset();
    } else {
        mSprite.move(mSpeed * dt.asSeconds(), 0);
        if (mSprite.getPosition().x > 1920) mActive = false;
    }
}

void Cloud::render(sf::RenderWindow& window) {
    if (mActive) window.draw(mSprite);
}