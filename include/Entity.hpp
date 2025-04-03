// Entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Texture {
 public:
  Entity(const std::string& texturePath, float x, float y);
  void setPosition(float x, float y);
  void draw(sf::RenderWindow& window);

 private:
  sf::Texture texture;
  sf::Sprite sprite;
};

#endif  // ENTITY_HPP