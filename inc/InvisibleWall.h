#pragma once
#include <Collisionable.h>
#include <SFML/Graphics.hpp>

struct InvisibleWall: ICollisionable
{
  public:
       InvisibleWall(const sf::FloatRect& wall = sf::FloatRect());
  bool isPossibleOverlap(const sf::Sprite& sprite) const noexcept override;
  
  private:
  sf::FloatRect _wall;
};
