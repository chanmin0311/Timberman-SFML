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

class Game {
   public:
    Game();
    void run();

   private:
    void processInput();
    void update(sf::Time dt);
    void render();

    // Variables to be rendered in the window
    sf::RenderWindow mWindow;

    sf::Texture mTextureBackground;
    sf::Sprite mSpriteBackground;

    sf::Texture mTextureTree;
    sf::Sprite mSpriteTree;

    sf::Clock mClock;

    sf::Font mFont;
    sf::Text mMessage;
    sf::Text mScoreText;
    int mScore;

    // Entity vector
    // This vector will hold all the entities in the game
    std::vector<std::unique_ptr<Entity>> mEntities;

    // Game state variables
    bool mPaused;
};

#endif  // GAME_HPP