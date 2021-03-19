
  #include <Bullet.h>
  #include <Game.h>

  Bullet::Bullet(const sf::Vector2f& spawnPos, EDir dir)
  {
    if(!texture.loadFromFile("media/bulletSprite.png"))
    {

    }
    else
    {
      sprite.setTexture(texture);
      sprite.setPosition(spawnPos);
      
      // float angle{};
      // switch(dir)
      // {
      //   case EDir::UP: 
      //         break;

      //   case EDir::DOWN: 
      //        angle = 180.f;

      //   case EDir::LEFT: 
      //        angle = 90.f;

      //   case EDir::RIGHT: 
      //       angle = -90.f;

      // }

      // sprite.setRotation(angle);
    }

  }

  void Bullet::Tick(sf::Time deltaTime)
  {

  }

  bool Bullet::isPossibleOverlap(const sf::Sprite& sprite) const noexcept
  {
      return true;
  }

void Bullet::render(sf::RenderWindow& window)
{
  window.draw(sprite);
}
