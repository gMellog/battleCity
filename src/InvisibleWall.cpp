#include <InvisibleWall.h>

InvisibleWall::InvisibleWall(const sf::FloatRect& wall)
:
_wall{wall}
{

}


bool InvisibleWall::isPossibleOverlap(const sf::Sprite& sprite) const noexcept
{
     return !_wall.intersects(sprite.getGlobalBounds());
}
