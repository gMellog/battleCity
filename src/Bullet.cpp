
  #include <Bullet.h>
  #include <Game.h>

  Bullet::Bullet(float speed, const sf::Vector2f& spawnPos, EDir dir)
  :
  _speed{speed}
  {
    if(!texture.loadFromFile("media/bulletSprite.png"))
    {

    }
    else
    {
      sprite.setTexture(texture);
      sprite.setPosition(spawnPos);
      
      float angle{};
      switch(dir)
      {
        case EDir::UP: 
              flyOffset.x = 0.f;
              flyOffset.y = -speed;
              break;

        case EDir::DOWN: 
             angle = 180.f;
              flyOffset.x = 0.f;
              flyOffset.y = speed;
             
             break;
        case EDir::LEFT: 
             angle = -90.f;
              flyOffset.x = -speed;
              flyOffset.y = 0;

             break;
        case EDir::RIGHT: 
             angle = 90.f;
              flyOffset.x = speed;
              flyOffset.y = 0.f;
             
             break;
      }
      
      sprite.setRotation(angle);
    }

  }

  void Bullet::tick(sf::Time deltaTime)
  {
     const auto overlappedActor = Game::tryToOverlap(this);
     if(overlappedActor != "")
     {
        if(overlappedActor == "Brick" || overlappedActor == "InvisibleWall" || overlappedActor == "Stone")
        {
          Game::removeActor(this);
        }
     }

        if(!isPendingToKill())
          sprite.move(flyOffset * deltaTime.asSeconds());
  
  }

  bool Bullet::isPossibleOverlap(const sf::FloatRect& area) const noexcept
  {
      return sprite.getGlobalBounds().intersects(area);
  }

void Bullet::render(sf::RenderWindow& window)
{
  window.draw(sprite);
}

sf::FloatRect Bullet::getBounds() const noexcept
{
  return sprite.getGlobalBounds();
}

std::string Bullet::getType() const
{
  return "Bullet";
}

void Bullet::overlap(const std::string& Type)
{

}


void Bullet::removeImpl()
{
   sprite.setColor(sf::Color(0,0,0,0));
}
