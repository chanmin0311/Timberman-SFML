// Game.hpp
#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Bee.hpp"
#include "Cloud.hpp"
#include "Entity.hpp"
#include "Hud.hpp"
#include "Branch.hpp"
#include "Player.hpp"

class Game {
   public:
    Game();
    void run();

   private:
    // Function to process input
    // This function will be used to process the input from the user
    void processInput();
    // Function to update the game
    // This function will be used to update the game
    void update(sf::Time dt);
    // Function to render the game
    // This function will be used to render the game
    void render();

    // Variables to be rendered in the window
    sf::RenderWindow mWindow;

    // Background and tree textures and sprites
    sf::Texture mTextureBackground;
    sf::Sprite mSpriteBackground;

    // Tree texture and sprite
    sf::Texture mTextureTree;
    sf::Sprite mSpriteTree;
    sf::Sprite mSpriteTree1;
    sf::Sprite mSpriteTree2;

    // Log texture and sprite
    sf::Texture mLogTexture;
    sf::Sprite mLogSprite1;
    sf::Sprite mLogSprite2;
    
    // Clock to measure time
    // This clock will be used to measure the time between frames
    sf::Clock mClock;

    // Entity vector
    // This vector will hold all the entities in the game
    std::vector<std::unique_ptr<Entity>> mEntities;

    // Objects for the game
    // HUD object
    Hud mHud;
    // Branch object
    Branch mBranch;
    // Player object
    Player mPlayer;
};

#endif  // GAME_HPP