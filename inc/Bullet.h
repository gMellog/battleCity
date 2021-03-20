#pragma once
#include <Actor.h>
#include <Toolchain.h>
#include <iostream>

struct Bullet : Actor
{
  Bullet(float speed, const sf::Vector2f& spawnPos, EDir dir);

  void tick(sf::Time deltaTime) override;
  bool isPossibleOverlap(const sf::FloatRect& area) const noexcept override;
  void render(sf::RenderWindow& window) override;
  void overlap(const std::string& Type) override;
  sf::FloatRect getBounds() const noexcept override;
  std::string getType() const override;

  private:
  void removeImpl() override;

  float _speed;
  sf::Sprite sprite;
  sf::Texture texture;
  sf::Vector2f flyOffset;
};
