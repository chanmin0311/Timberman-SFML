// Game.cpp
#include "../include/Game.hpp"

Game::Game()
    : mWindow(sf::VideoMode(1920, 1080), "Timber!!!", sf::Style::Fullscreen),
      mHud()
      {
    // Find the background texture and load it
    // Set the background texture
    if (!mTextureBackground.loadFromFile("../assets/images/background.png")) {
        throw std::runtime_error("Failed to load background texture");
    }
    // Set the background sprite
    mSpriteBackground.setTexture(mTextureBackground);

    // Find the tree texture and load it
    // Set the tree texture
    if (!mTextureTree.loadFromFile("../assets/images/tree.png")) {
        throw std::runtime_error("Failed to load tree texture");
    }
    // Set the tree sprite
    mSpriteTree.setTexture(mTextureTree);
    // Set the tree sprite position to cnter of the screen
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        mHud.setPaused(false);
        mHud.setScore(0);
        mHud.setTimeRemaining(6.0f);
    }
}

void Game::update(sf::Time dt) {
    if (mHud.getPaused() == false) {
        for (auto& entity : mEntities) {
            entity->update(dt);
        }
        mHud.updateTimeBar(dt);
    }
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mSpriteBackground);
    for (auto& entity : mEntities) {
        entity->render(mWindow);
    }
    mWindow.draw(mSpriteTree);
    // Draw the score
    mHud.getScoreText().setString("Score: " + std::to_string(mHud.getScore()));
    mHud.renderScoreText(mWindow);
    // // Draw the message
    if (mHud.getPaused()) {
        mHud.renderMessageText(mWindow);
    }
    mHud.renderTimeBar(mWindow);
    mWindow.display();
}