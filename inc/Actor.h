#pragma once
#include <SFML/Graphics.hpp>

struct IActor
{
  virtual ~IActor() = default;
  virtual bool isPossibleOverlap(const sf::Sprite& sprite) const noexcept = 0;
  virtual void Tick(sf::Time deltaTime) = 0;
  virtual void render(sf::RenderWindow& window) = 0;
};
