#pragma once
#include <SFML/Graphics.hpp>

struct ICollisionable
{
  virtual ~ICollisionable() = default;
  virtual bool isPossibleOverlap(const sf::Sprite& sprite) const noexcept = 0;
};
