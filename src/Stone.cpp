#include <Stone.h>

Stone::Stone(const sf::Vector2f& pos)
{
  
  if(!_texture.loadFromFile("media/groundSprites.png"))
  {
      
  }
  else
  {
    _sprite.setTexture(_texture);
    _sprite.setPosition(pos);
    _sprite.setTextureRect(sf::IntRect(48,0,24,24));
   
  }
}

sf::FloatRect Stone::getBounds() const noexcept
{
  return _sprite.getGlobalBounds();
}

bool Stone::isPossibleOverlap(const sf::FloatRect& area) const noexcept
{
     return _sprite.getGlobalBounds().intersects(area);
}

void Stone::tick(sf::Time deltaTime)
{

}

void Stone::render(sf::RenderWindow& window)
{
  window.draw(_sprite);
}

void Stone::overlap(const std::string& Type)
{

}

void Stone::removeImpl()
{
  _sprite.setColor(sf::Color(0,0,0,0));
}

std::string Stone::getType() const
{
  return "Stone";
}
