// Hud.cpp
#include "../include/Hud.hpp"

Hud::Hud() : mScore(0) {
    // Font path to read and load the font
    if (!mFont.loadFromFile("../assets/fonts/KOMIKAP_.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    // Set the font to our text
    mMessage.setFont(mFont);
    mScoreText.setFont(mFont);

    // Assign the actual text
    mMessage.setString("Press Enter to start!");
    mScoreText.setString("Score: ");

    // Set the size of the text
    mMessage.setCharacterSize(75);
    mScoreText.setCharacterSize(75);

    // Set the color of the text
    mMessage.setFillColor(sf::Color::White);
    mScoreText.setFillColor(sf::Color::White);

    // Position the text
    sf::FloatRect textRect = mMessage.getLocalBounds();
    mMessage.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
    mMessage.setPosition(960, 540);  // Center of the screen
    mScoreText.setPosition(20, 20);  // Top left corner
    mScoreText.setString("Score: " + std::to_string(mScore));
}

sf::Text& Hud::getMessage() { return mMessage; }
sf::Text& Hud::getScoreText() { return mScoreText; }
int Hud::getScore() { return mScore; }
void Hud::renderMessage(sf::RenderWindow& window) { window.draw(mMessage); }
void Hud::renderScore(sf::RenderWindow& window) { window.draw(mScoreText); }