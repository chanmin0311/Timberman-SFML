// Player.cpp
#include "../include/Player.hpp"

Player::Player()
    : mPlayerSide(playerPosition::side::LEFT), mIsPlayerAlive(true), mAcceptInput(false) {
    // Axe file to read and load it
    if (!mAxe.mAxeTexture.loadFromFile("../assets/images/axe.png")) {
        throw std::runtime_error("Failed to load axe texture");
    }
    mAxe.mAxeSprite.setTexture(mAxe.mAxeTexture);
    mAxe.mAxeSprite.setPosition(mAxe.AXE_POSITION_LEFT, 820);

    // Log file to read and load it
    if (!mLog.mLogTexture.loadFromFile("../assets/images/log.png")) {
        throw std::runtime_error("Failed to load log texture");
    }
    mLog.mLogSprite.setTexture(mLog.mLogTexture);
    mLog.mLogSprite.setPosition(-2000, -2000);

    // RIP file to read and load it
    if (!mRip.mRipTexture.loadFromFile("../assets/images/rip.png")) {
        throw std::runtime_error("Failed to load rip texture");
    }
    mRip.mRipSprite.setTexture(mRip.mRipTexture);
    mRip.mRipSprite.setPosition(-2000, -2000);

    // Player file to read and load it
    if (!mPlayerTexture.loadFromFile("../assets/images/player.png")) {
        throw std::runtime_error("Failed to load player texture");
    }

    mPlayerSprite.setTexture(mPlayerTexture);
    mPlayerSprite.setPosition(PLAYER_LEFT, PLAYERR_POSITION_Y);
}

void Player::update(Hud& hud, Branch& branch) {
    auto playerSide = getPlayerSide();

    if (playerSide == playerPosition::side::RIGHT) {
        hud.setScore(hud.getScore() + 1);
        // Add to the amout of time remaining
        hud.setTimeRemaining(hud.getTimeRemaining() + (2 / hud.getScore()) + .15f);
        mAxe.mAxeSprite.setPosition(mAxe.AXE_POSITION_RIGHT, mAxe.mAxeSprite.getPosition().y);
        mPlayerSprite.setPosition(PLAYER_RIGHT, PLAYERR_POSITION_Y);
        // Update the braches
        branch.updateBranches(hud.getScore());

        // Set the log flying to the left
        mLog.mLogSprite.setPosition(810, 720);
        mLog.logSpeedX = -5000;
        mLog.logActive = true;
        mAcceptInput = false;
    }

    if (playerSide == playerPosition::side::LEFT) {
        hud.setScore(hud.getScore() + 1);
        // Add to the amout of time remaining
        hud.setTimeRemaining(hud.getTimeRemaining() + (2 / hud.getScore()) + .15f);
        mAxe.mAxeSprite.setPosition(mAxe.AXE_POSITION_LEFT, mAxe.mAxeSprite.getPosition().y);
        mPlayerSprite.setPosition(PLAYER_LEFT, PLAYERR_POSITION_Y);
        // Update the braches
        branch.updateBranches(hud.getScore());
        // Set the log flying to the right
        mLog.mLogSprite.setPosition(810, 720);
        mLog.logSpeedX = 5000;
        mLog.logActive = true;
        mAcceptInput = false;
    }
}

void Player::updateLog(sf::Time dt) {
    sf::Sprite& logSprite = mLog.mLogSprite;
    logSprite.setPosition(logSprite.getPosition().x + (mLog.logSpeedX * dt.asSeconds()),
                          logSprite.getPosition().y + (mLog.logSpeedY * dt.asSeconds()));
    // Has the log reached the right  hand edge?
    if (logSprite.getPosition().x < -100 || logSprite.getPosition().x > 2000) {
        mLog.logActive = false;
        logSprite.setPosition(810, 720);
    }
}

void Player::render(sf::RenderWindow& window) {
    // Draw the player
    window.draw(mPlayerSprite);
    // Draw the axe
    window.draw(mAxe.mAxeSprite);
    // Draw the log
    window.draw(mLog.mLogSprite);
    // Draw the RIP
    window.draw(mRip.mRipSprite);
}

// Getters and setters
sf::Sprite& Player::getPlayerSprite() { return mPlayerSprite; }
sf::Sprite& Player::getAxeSprite() { return mAxe.mAxeSprite; }
sf::Sprite& Player::getLogSprite() { return mLog.mLogSprite; }
bool Player::isLogActive() const { return mLog.logActive; }
sf::Sprite& Player::getRipSprite() { return mRip.mRipSprite; }
bool Player::isPlayerAlive() const { return mIsPlayerAlive; }
bool Player::isAcceptInput() const { return mAcceptInput; }
playerPosition::side Player::getPlayerSide() const { return mPlayerSide; }

void Player::setPlayerAlive(bool isAlive) { mIsPlayerAlive = isAlive; }
void Player::setAcceptInput(bool acceptInput) { mAcceptInput = acceptInput; }
void Player::setPlayerSide(playerPosition::side side) { mPlayerSide = side; }
