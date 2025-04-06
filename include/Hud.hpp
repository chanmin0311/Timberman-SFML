// Hud.hpp
#pragma once
#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>

class Hud {
   public:
    // Constructor
    Hud();

    // Getters
    sf::Text& getMessage();
    sf::Text& getScoreText();
    int getScore();

    // Render functions
    void renderMessage(sf::RenderWindow& window);
    void renderScore(sf::RenderWindow& window);

   private:
    sf::Font mFont;
    sf::Text mMessage;
    sf::Text mScoreText;
    int mScore;
};

#endif  // HUD_HPP
