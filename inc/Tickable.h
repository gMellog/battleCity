#pragma once
#include <SFML/Graphics.hpp>

struct ITickable
{
  virtual ~ITickable() = default;
  virtual void Tick(sf::Time deltaTime) = 0;
};
