#pragma once
#include <Actor.h>


struct Base : Actor
{
  Base(const sf::Vector2f& pos);
  bool isPossibleOverlap(const sf::FloatRect& area) const noexcept override;
  void tick(sf::Time deltaTime) override;
  void overlap(const std::string& Type) override;
  void render(sf::RenderWindow& window) override;
  std::string getType() const override;
  sf::FloatRect getBounds() const noexcept override;
  
  private:
  void removeImpl() override;

  private:
  sf::Texture _texture;
  sf::Sprite _sprite;
};
