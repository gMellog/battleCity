#pragma once
#include <SFML/Graphics.hpp>

struct Actor
{
  Actor();
  virtual ~Actor() = default;
  virtual bool isPossibleOverlap(const sf::FloatRect& area) const noexcept = 0;
  virtual void overlap(const std::string& Type) = 0;
  virtual void tick(sf::Time deltaTime) = 0;
  virtual void render(sf::RenderWindow& window) = 0;
  virtual std::string getType() const = 0;
  virtual sf::FloatRect getBounds() const noexcept = 0;

  void remove();
  bool isPendingToKill() const noexcept;

  private:
  virtual void removeImpl() = 0;

  private:
  bool pendingToKill;

};
