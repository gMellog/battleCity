#include <Base.h>
#include <Game.h>

Base::Base(const sf::Vector2f& pos)
{
  
  if(!_texture.loadFromFile("media/baseSprite.png"))
  {
      
  }
  else
  {
    _sprite.setTexture(_texture);
    _sprite.setPosition(pos);
    _sprite.setTextureRect(sf::IntRect(0,0,48,48));
   
  }
}

sf::FloatRect Base::getBounds() const noexcept
{
  return _sprite.getGlobalBounds();
}

bool Base::isPossibleOverlap(const sf::FloatRect& area) const noexcept
{
     return _sprite.getGlobalBounds().intersects(area);
}

void Base::tick(sf::Time deltaTime)
{

}

void Base::render(sf::RenderWindow& window)
{
  window.draw(_sprite);
}

void Base::overlap(const std::string& Type)
{
  if(Type == "Bullet")
  {
    //Change sprite for RIP image 48x48
    //Notify somehow that player lost
  }
}

void Base::removeImpl()
{
  _sprite.setColor(sf::Color(0,0,0,0));
}

std::string Base::getType() const
{
  return "Base";
}
