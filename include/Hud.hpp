// Hud.hpp
#pragma once
#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Hud {
   public:
    // Constructor
    Hud();

    // Getters
    sf::Text& getMessage();
    sf::Text& getScoreText();
    int getScore();
    float getTimeRemaining();
    bool getPaused();
    sf::RectangleShape getTimeBar();
    sf::Sound& getTimeOut();

    // Setters
    void setMessageText(const std::string& msg);
    void setScoreText(const std::string& score);
    void setScore(int score);
    void setTimeRemaining(float time);
    void setPaused(bool paused);

    // Render functions
    void renderMessageText(sf::RenderWindow& window);
    void renderScoreText(sf::RenderWindow& window);
    void renderTimeBar(sf::RenderWindow& window);

    // Update function
    void updateTimeBar(sf::Time dt);

    // Constants for the time bar
    const float TIMEBAR_WIDTH = 400;
    const float TIMEBAR_HEIGHT = 80;

   private:
    // Font object
    sf::Font mFont;

    // Text objects
    sf::Text mMessageText;
    sf::Text mScoreText;
    int mScore;

    // Time bar
    sf::Time mGameTimeTotal;
    sf::RectangleShape mTimeBar;
    float mTimeRemaining;
    float mTimeBarWidthPerSecond;

    bool mPaused;

    // Sounds
    sf::SoundBuffer mTimeOutBuffer;
    sf::Sound mSdTimeOut;
};

#endif  // HUD_HPP
