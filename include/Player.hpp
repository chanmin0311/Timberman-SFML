// Player.hpp
#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/Hud.hpp"
#include "../include/Branch.hpp"

// Player constants
const float PLAYER_RIGHT = 1200;
const float PLAYER_LEFT = 580;
const float PLAYERR_POSITION_Y = 720;

class Player {
   private:
    // Axe class
    typedef struct axe {
        // Constants for the axe position
        const float AXE_POSITION_LEFT = 700;
        const float AXE_POSITION_RIGHT = 1075;

        // Axe texture and sprite
        sf::Texture mAxeTexture;
        sf::Sprite mAxeSprite;
    } Axe;

    // Log class
    typedef struct log {
        // Useful log related variables
        bool logActive = false;
        float logSpeedX = 1000;
        float logSpeedY = -1500;

        // Log texture and sprite
        sf::Texture mLogTexture;
        sf::Sprite mLogSprite;
    } Log;

    // RIP class
    typedef struct rip {
        // RIP texture and sprite
        sf::Texture mRipTexture;
        sf::Sprite mRipSprite;
    } Rip;

    // Axe, log and RIP objects
    Log mLog;
    Axe mAxe;
    Rip mRip;

    // Player texture and sprite
    sf::Texture mPlayerTexture;
    sf::Sprite mPlayerSprite;
    side mPlayerSide;

    // Player's status
    bool mIsPlayerAlive;
    bool mAcceptInput;

    // sounds
    sf::SoundBuffer mChopBuffer;
    sf::Sound mSdChop;
    sf::SoundBuffer mDeathBuffer;
    sf::Sound mSdDeath;

   public:
    Player();
    void update(Hud& hud, Branch& branch, side prevSide);
    void updateLog(sf::Time dt);
    void render(sf::RenderWindow& window);

    // Getters
    sf::Sprite& getAxeSprite();
    sf::Sprite& getLogSprite();
    bool isLogActive() const;
    sf::Sprite& getRipSprite();
    sf::Sprite& getPlayerSprite();
    bool isPlayerAlive() const;
    bool isAcceptInput() const;
    side getPlayerSide() const;
    sf::Sound& getChop();
    sf::Sound& getDeath();

    // Setters
    void setPlayerAlive(bool isAlive);
    void setAcceptInput(bool acceptInput);
    void setPlayerSide(side side);
};

#endif