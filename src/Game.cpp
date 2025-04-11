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
    mSpriteTree1.setTexture(mTextureTree);
    mSpriteTree2.setTexture(mTextureTree);

    // Set the tree sprite position to cnter of the screen
    mSpriteTree.setPosition((mWindow.getSize().x / 2) - (mTextureTree.getSize().x / 2), 0);
    mSpriteTree1.setPosition(-100, -40);
    mSpriteTree2.setPosition(1600, 0);

    if (!mLogTexture.loadFromFile("../assets/images/log.png")) {
        throw std::runtime_error("Faild to load log texture");
    }
    mLogSprite1.setTexture(mLogTexture);
    mLogSprite1.setPosition(-100, 860);
    mLogSprite2.setTexture(mLogTexture);
    mLogSprite2.setPosition(1600, 900);



    // Create Entities
    mEntities.emplace_back(std::make_unique<Bee>());
    mEntities.emplace_back(std::make_unique<Cloud>(0));
    mEntities.emplace_back(std::make_unique<Cloud>(150));
    mEntities.emplace_back(std::make_unique<Cloud>(300));
}

void Game::run() {
    mBranch.updateBranches();
    mBranch.updateBranches();
    mBranch.updateBranches();
    mBranch.updateBranches();
    mBranch.updateBranches();
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
            mBranch.setBranchPosition(i, side::NONE);
        }

        mPlayer.getRipSprite().setPosition(675, 2000);
        mPlayer.getPlayerSprite().setPosition(PLAYER_RIGHT, PLAYERR_POSITION_Y);
        mPlayer.setAcceptInput(true);
    }
    if (mPlayer.isAcceptInput()) {
        // Get player's current position
        auto prevSide = mPlayer.getPlayerSide();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            mPlayer.setPlayerSide(side::RIGHT);
            mPlayer.update(mHud, mBranch, prevSide);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            mPlayer.setPlayerSide(side::LEFT);
            mPlayer.update(mHud, mBranch, prevSide);
        }
    }
}

void Game::update(sf::Time dt) {
    mBranch.update();
    if (mPlayer.isLogActive()) {
        mPlayer.updateLog(dt);
    }
    if (mBranch.getBranchPosition(5) == mPlayer.getPlayerSide()) {
        mPlayer.setPlayerAlive(false);
        mHud.setPaused(true);
        mPlayer.setAcceptInput(false);

        auto side = mPlayer.getPlayerSide();
        switch (side) {
            case side::RIGHT:
                // Set Rip's position to right
                // Adjusting Rip's Y coord
                mPlayer.getRipSprite().setPosition(PLAYER_RIGHT, PLAYERR_POSITION_Y + 50);
                break;
            case side::LEFT:
                // Set Rip's position to left
                mPlayer.getRipSprite().setPosition(PLAYER_LEFT, PLAYERR_POSITION_Y + 50);
                break;
        }
        mPlayer.getPlayerSprite().setPosition(2000, 660);

        mHud.getMessage().setString("SQUISHED!!");

        sf::FloatRect textRect = mHud.getMessage().getLocalBounds();
        mHud.getMessage().setOrigin(textRect.left + textRect.width / 2.0f,
                                    textRect.top + textRect.height / 2.0f);

        mHud.getMessage().setPosition(1920 / 2.0f, 1080 / 2.0f);
    }
    if (mHud.getPaused() == false) {
        for (auto& entity : mEntities) {
            entity->update(dt);
        }
        mHud.updateTimeBar(dt);
    }
}

void Game::render() {
    // Clear before drawing
    mWindow.clear();

    // Draw background
    mWindow.draw(mSpriteBackground);

    // Draw clouds and bee
    for (auto& entity : mEntities) {
        entity->render(mWindow);
    }

    // Draw trees
    mWindow.draw(mSpriteTree);

    mWindow.draw(mSpriteTree1);
    mWindow.draw(mLogSprite1);

    mWindow.draw(mSpriteTree2);
    mWindow.draw(mLogSprite2);
    // Draw the score
    mHud.getScoreText().setString("Score: " + std::to_string(mHud.getScore()));
    mHud.renderScoreText(mWindow);

    // Draw branches
    mBranch.render(mWindow);

    // Draw the player
    mPlayer.render(mWindow);
    // Draw the message
    if (mHud.getPaused()) {
        mHud.renderMessageText(mWindow);
    }
    mHud.renderTimeBar(mWindow);

    mWindow.display();
}