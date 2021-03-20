
#include <Brick.h>
#include <Game.h>

Brick::Brick(const sf::Vector2f& pos)
{
  if(!_texture.loadFromFile("media/groundSprites.png"))
  {
      std::cout << "didn't get it" << std::endl;
  }
  else
  {
    _sprite.setTexture(_texture);
    _sprite.setPosition(pos);
    _sprite.setTextureRect(sf::IntRect(24,0,24,24));
  }
}

sf::FloatRect Brick::getBounds() const noexcept
{
  return _sprite.getGlobalBounds();
}

bool Brick::isPossibleOverlap(const sf::FloatRect& area) const noexcept
{
     return _sprite.getGlobalBounds().intersects(area);
}

void Brick::tick(sf::Time deltaTime)
{

}

void Brick::render(sf::RenderWindow& window)
{
  window.draw(_sprite);
}

void Brick::overlap(const std::string& Type)
{
  if(Type == "Bullet")
  {
    auto& game = Game::get();
    game.removeActor(this);
  }

}

void Brick::removeImpl()
{
  _sprite.setColor(sf::Color(0,0,0,0));
}

std::string Brick::getType() const
{
  return "Brick";
}

