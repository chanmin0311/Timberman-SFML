// Hud.cpp
#include "../include/Hud.hpp"

Hud::Hud() : mScore(0), mPaused(true) {
    // Font path to read and load the font
    std::string fontPath = "../assets/fonts/KOMIKAP_.ttf";
    if (!mFont.loadFromFile(fontPath)) {
        throw std::runtime_error("Failed to load font");
    }

    // Set the font to our text
    mMessageText.setFont(mFont);
    mScoreText.setFont(mFont);

    // Assign the actual text
    mMessageText.setString("Press Enter to start!");
    mScoreText.setString("Score: ");

    // Set the size of the text
    mMessageText.setCharacterSize(75);
    mScoreText.setCharacterSize(75);

    // Set the color of the text
    mMessageText.setFillColor(sf::Color::White);
    mScoreText.setFillColor(sf::Color::White);

    // Position the text
    sf::FloatRect textRect = mMessageText.getLocalBounds();
    mMessageText.setOrigin(textRect.left + textRect.width / 2.0f,
                           textRect.top + textRect.height / 2.0f);
    mMessageText.setPosition(960, 540);  // Center of the screen
    mScoreText.setPosition(20, 20);      // Top left corner
    mScoreText.setString("Score: " + std::to_string(mScore));

    // Set the size of the time bar
    mTimeBar.setSize(sf::Vector2f(TIMEBAR_WIDTH, TIMEBAR_HEIGHT));
    // Fill the time bar with a color
    mTimeBar.setFillColor(sf::Color::Red);
    // Set the position of the time bar
    mTimeBar.setPosition((1920 / 2) - (mTimeBar.getSize().x / 2), 980);
    mTimeRemaining = 6.0f;
    mTimeBarWidthPerSecond = mTimeBar.getSize().x / mTimeRemaining;

    // Set sound effects
    if (!mTimeOutBuffer.loadFromFile("../assets/sounds/out_of_time.wav")) {
        throw std::runtime_error("Failed to load time_out audio");
    }
    mSdTimeOut.setBuffer(mTimeOutBuffer);
}

void Hud::renderMessageText(sf::RenderWindow& window) { window.draw(mMessageText); }
void Hud::renderScoreText(sf::RenderWindow& window) { window.draw(mScoreText); }
void Hud::renderTimeBar(sf::RenderWindow& window) { window.draw(mTimeBar); }

void Hud::updateTimeBar(sf::Time dt) {
    // Subtract from the amout of times remaining
    mTimeRemaining -= dt.asSeconds();

    // Size up the time bar
    mTimeBar.setSize(sf::Vector2f((mTimeBarWidthPerSecond * mTimeRemaining), 80));
    if (mTimeRemaining <= 0.0f) {
        // pause the game
        mPaused = true;
        mMessageText.setString("Out of Time!!");
        sf::FloatRect textRect = mMessageText.getLocalBounds();
        mMessageText.setOrigin(textRect.left + textRect.width / 2.0f,
                               textRect.top + textRect.height / 2.0f);
        mMessageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

        // Play the sound effect
        mSdTimeOut.play();
    }
}

// Getter and setter
sf::Text& Hud::getMessage() { return mMessageText; }
sf::Text& Hud::getScoreText() { return mScoreText; }
int Hud::getScore() { return mScore; }
float Hud::getTimeRemaining() { return mTimeRemaining; }
bool Hud::getPaused() { return mPaused; }
sf::RectangleShape Hud::getTimeBar() { return mTimeBar; }
sf::Sound& Hud::getTimeOut() { return mSdTimeOut; }

void Hud::setMessageText(const std::string& msg) { mMessageText.setString(msg); }
void Hud::setScoreText(const std::string& score) { mScoreText.setString(score); }
void Hud::setScore(int score) { mScore = score; }
void Hud::setTimeRemaining(float time) { mTimeRemaining = time; }
void Hud::setPaused(bool paused) { mPaused = paused; }
