#pragma once
#include <Actor.h>

struct InvisibleWall: IActor
{
  public:
       InvisibleWall(const sf::FloatRect& wall = sf::FloatRect());
  bool isPossibleOverlap(const sf::Sprite& sprite) const noexcept override;
  void Tick(sf::Time deltaTime) override;
  void render(sf::RenderWindow& window) override;
  
  private:
  sf::FloatRect _wall;
};
