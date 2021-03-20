#include <InvisibleWall.h>

InvisibleWall::InvisibleWall(const sf::FloatRect& wall)
:
_wall{wall}
{

}


bool InvisibleWall::isPossibleOverlap(const sf::FloatRect& area) const noexcept
{
     return _wall.intersects(area);
}

void InvisibleWall::tick(sf::Time deltaTime)
{

}

void InvisibleWall::overlap(const std::string& Type)
{

}

void InvisibleWall::render(sf::RenderWindow& window)
{

}

void InvisibleWall::removeImpl()
{

}

sf::FloatRect InvisibleWall::getBounds() const noexcept
{
  return _wall;
}

std::string InvisibleWall::getType() const
{
  return "InvisibleWall";
}
