// Game.cpp
#include "../include/Game.hpp"

Game::Game()
    : window(sf::VideoMode(1920, 1080), "Timber!", sf::Style::Fullscreen),
      background("../assets/images/background.png", 0, 0),
      tree("../assets/images/tree.png", (window.getSize().x / 2) -150, 0),
      cloud1("../assets/images/cloud.png", 0, 0),
      cloud2("../assets/images/cloud.png", 0, 150),
      cloud3("../assets/images/cloud.png", 0, 300),
      bee("../assets/images/bee.png", 0, 800) {}

void Game::run() {
    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        window.clear();
        background.draw(window);
        tree.draw(window);
        cloud1.draw(window);
        cloud2.draw(window);
        cloud3.draw(window);
        bee.draw(window);
        window.display();
    }
}
