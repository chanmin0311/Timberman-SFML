// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Game {
   public:
    Game();
    void run();

   private:
    sf::RenderWindow window;
    Entity background;
    Entity tree;
    Entity cloud1;
    Entity cloud2;
    Entity cloud3;
    Entity bee;
};

#endif  // GAME_HPP