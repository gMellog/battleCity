#pragma once
#include <Actor.h>
#include <Toolchain.h>

struct Bullet : IActor
{
  Bullet(const sf::Vector2f& spawnPos, EDir dir);
  void Tick(sf::Time deltaTime) override;
  bool isPossibleOverlap(const sf::Sprite& sprite) const noexcept override;
  void render(sf::RenderWindow& window) override;

  private:
  sf::Sprite sprite;
  sf::Texture texture;
};
