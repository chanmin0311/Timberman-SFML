// Game.cpp
#include "../include/Game.hpp"

Game::Game()
    : mWindow(sf::VideoMode(1920, 1080), "Timber!!!", sf::Style::Fullscreen),
      mHud(),
      mBranch(),
      mPlayer() {
    // Background and tree path to read
    std::string backgroundPath = "../assets/images/background.png";
    std::string treePath = "../assets/images/tree.png";

    // Find the background texture and load it
    // Set the background texture
    if (!mTextureBackground.loadFromFile(backgroundPath)) {
        throw std::runtime_error("Failed to load background texture");
    }
    // Set the background sprite
    mSpriteBackground.setTexture(mTextureBackground);

    // Find the tree texture and load it
    // Set the tree texture
    if (!mTextureTree.loadFromFile(treePath)) {
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
    mBranch.updateBranches(1);
    mBranch.updateBranches(2);
    mBranch.updateBranches(3);
    mBranch.updateBranches(4);
    mBranch.updateBranches(5);
    while (mWindow.isOpen()) {
        processInput();
        sf::Time dt = mClock.restart();
        update(dt);
        render();
    }
}

void Game::processInput() {
    // Process events
    // Event object
    sf::Event event;

    // Detect if the key is released
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::KeyReleased && !mHud.getPaused()) {
            mPlayer.setAcceptInput(true);
            mPlayer.getAxeSprite().setPosition(2000, mPlayer.getAxeSprite().getPosition().y);
        }
    }

    // Empty event queue by using poolEvent or waitEvent
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        mWindow.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        mHud.setPaused(false);
        mHud.setScore(0);
        mHud.setTimeRemaining(6.0f);

        // Make all the branches dissapear
        for (int i = 0; i < NUM_BRANCHES; i++) {
            mBranch.setBranchPosition(i, branchPosition::side::NONE);
        }

        mPlayer.getRipSprite().setPosition(675, 2000);
        mPlayer.getPlayerSprite().setPosition(PLAYER_LEFT, PLAYERR_POSITION_Y);
        mPlayer.setAcceptInput(true);
    }
    if (mPlayer.isAcceptInput()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            mPlayer.setPlayerSide(playerPosition::side::RIGHT);
            mPlayer.update(mHud, mBranch);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            mPlayer.setPlayerSide(playerPosition::side::LEFT);
            mPlayer.update(mHud, mBranch);
        }
    }
}

void Game::update(sf::Time dt) {
    mBranch.update();
    if (mPlayer.isLogActive()) {
        mPlayer.updateLog(dt);
    }
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

    // Draw branches
    mBranch.render(mWindow);

    // Draw the player
    mPlayer.render(mWindow);
    // // Draw the message
    if (mHud.getPaused()) {
        mHud.renderMessageText(mWindow);
    }
    mHud.renderTimeBar(mWindow);
    mWindow.display();
}