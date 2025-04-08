// Cloud.cpp
#include "../include/Cloud.hpp"

#include <random>

Cloud::Cloud(float baseY) : mActive(false), mSpeed(0.0f), mBaseY(baseY) {
    // Cloud path to read and load the cloud texture
    std::string cloudPath = "../assets/images/cloud.png";
    if (!mTexture.loadFromFile(cloudPath)) {
        throw std::runtime_error("Failed to load cloud texture");
    }
    mSprite.setTexture(mTexture);
    mSprite.setPosition(-200, baseY);
}

void Cloud::reset() {
    auto cloudSpeed = rand_int_uniform_dist(50, 200);
    auto cloudAltitude = rand_int_uniform_dist(0, 150);

    // Set cloud's attributes
    mSpeed = cloudSpeed;
    float altitude = cloudAltitude - 150 + mBaseY;
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