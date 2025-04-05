// Game.cpp
#include "../include/Game.hpp"

Game::Game()
    : mWindow(sf::VideoMode(1920, 1080), "Timber!!!", sf::Style::Fullscreen),
      mPaused(true),
      mScore(0) {
    // Find the font and load it
    if (!mFont.loadFromFile("../assets/fonts/KOMIKAP_.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    // Set up HUD (Heads Up Display)
    // Set the font to our test
    mMessage.setFont(mFont);
    mScoreText.setFont(mFont);
    // Assigin the actual text
    mMessage.setString("Press Enter to start!");
    mScoreText.setString("Score: 0");
    // Set the size of the text
    mMessage.setCharacterSize(75);
    mScoreText.setCharacterSize(100);
    // Set the color of the text
    mMessage.setFillColor(sf::Color::White);
    mScoreText.setFillColor(sf::Color::White);
    // Position the text
    // Get the bounding box of the text
    sf::FloatRect textRect = mMessage.getLocalBounds();
    // Set the origin of the text to the center
    mMessage.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
    // Set the position of the text to the center of the screen
    mMessage.setPosition(mWindow.getSize().x / 2.0f, mWindow.getSize().y / 2.0f);
    // Set the position of the score text to the top left corner
    mScoreText.setPosition(20, 20);

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
        mPaused = false;
    }
}

void Game::update(sf::Time dt) {
    if (mPaused == false) {
        for (auto& entity : mEntities) {
            entity->update(dt);
        }
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
    mScoreText.setString("Score: " + std::to_string(mScore));
    mWindow.draw(mScoreText);
    // Draw the message
    if (mPaused) {
        mWindow.draw(mMessage);
    }
    mWindow.display();
}