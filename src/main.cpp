#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Timber!", sf::Style::Fullscreen);

    // Create a texture to hold a graphic on the GPU
    sf::Texture textureBackground;
    if (!textureBackground.loadFromFile("../assets/images/background.png")) {
        return EXIT_FAILURE;
    }

    // Create a sprite
    sf::Sprite spriteBackground;    
    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);
    // Set the sprite to cover the whole window
    spriteBackground.setPosition(0, 0);

	while (window.isOpen()) {
		/*
		***** Handle the players 
		*/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
        
		/*
		***** Update the scene
		*/
	
		// Draw game scenes here
        // Clear everthing from the last frame window.clear()
        window.clear();
        // Draw the background
        window.draw(spriteBackground);
        // Display the contents of the window
        window.display();
	}
	return 0;
}