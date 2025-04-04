// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.hpp"
#include "Bee.hpp"
#include "Cloud.hpp"

class Game {
    public:
    Game();
    void run();

    private:
    void processInput();
    void update(sf::Time dt);
    void render();

    sf::RenderWindow mWindow;
    sf::Texture mTextureBackground;
    sf::Sprite mSpriteBackground;
    sf::Texture mTextureTree;
    sf::Sprite mSpriteTree;
    sf::Clock mClock;
    std::vector<std::unique_ptr<Entity>> mEntities;
};

#endif  // GAME_HPP