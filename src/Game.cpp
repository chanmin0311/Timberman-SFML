// Game.cpp
#include "../include/Game.hpp"

Game::Game() : mWindow(sf::VideoMode(1920, 1080), "Timber!!!", sf::Style::Fullscreen) {
    mTextureBackground.loadFromFile("../assets/images/background.png");
    mSpriteBackground.setTexture(mTextureBackground);

    mTextureTree.loadFromFile("../assets/images/tree.png");
    mSpriteTree.setTexture(mTextureTree);
    mSpriteTree.setPosition((mWindow.getSize().x / 2) - (mTextureTree.getSize().x / 2), 0);

    // Create Entities
    mEntities.emplace_back(std::make_unique<Bee>());
    mEntities.emplace_back(std::make_unique<Cloud>(0));
    mEntities.emplace_back(std::make_unique<Cloud>(150));
    mEntities.emplace_back(std::make_unique<Cloud>(300));
}

void Game::run() {
    while (mWindow.isOpen()) {
        processInput();
        sf::Time dt = mClock.restart();
        update(dt);
        render();
    }
}

void Game::processInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        mWindow.close();
    }
}

void Game::update(sf::Time dt) {
    for (auto& entity : mEntities) {
        entity->update(dt);
    }
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mSpriteBackground);
    for (auto& entity : mEntities) {
        entity->render(mWindow);
    }
    mWindow.draw(mSpriteTree);
    mWindow.display();
}