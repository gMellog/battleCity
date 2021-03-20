#include <Player.h>
#include <Game.h>
#include <iostream>

Player::Player(const sf::Vector2f& pos)
{
  currFrameCounter = 0;
  needFrameCounter = 2000;
  endReloadTime = 0.5f;
  PlayerSpeed = 100.f;
  shootPossibility = true;

  if(!texture.loadFromFile("media/playerSprites.png"))
  {

  }
  else
  {
    sprite.setTexture(texture);
    sprite.setPosition(pos);

    DrawSprite up{sf::IntRect(78,40,38,40),  sf::IntRect(117,40,38,40)};
    DrawSprite down{sf::IntRect(0,39,39,40), sf::IntRect(39,39,39,40)};
    DrawSprite left{sf::IntRect(78,0,39,39), sf::IntRect(117,0,39,39)};
    DrawSprite right{sf::IntRect(0,0,39,39), sf::IntRect(39,0,39,39)};

    drawSprites[UP] = up;
    drawSprites[DOWN] = down;
    drawSprites[LEFT] = left;
    drawSprites[RIGHT] = right;
    dir = EDir::UP;

    sprite.setTextureRect(up.get());
  }
}

sf::FloatRect Player::getBounds() const noexcept
{
  return sprite.getGlobalBounds();
}

std::string Player::getType() const
{
  return "Player";
}

void Player::overlap(const std::string& Type)
{

}

bool Player::isPossibleOverlap(const sf::FloatRect& area) const noexcept
{
    return sprite.getGlobalBounds().intersects(area);
}

void Player::tick(sf::Time deltaTime)
{
      sf::Vector2f movement(0.f, 0.f);

      if(!shootPossibility)
      {
        currReloadTime += deltaTime.asSeconds();
        if(currReloadTime >= endReloadTime)
        {
          shootPossibility = true;
          currReloadTime = 0.f;
        }
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      {
          movement.y -= PlayerSpeed;
          prepareForAnimationChange(EDir::UP);
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
          movement.y += PlayerSpeed;
          prepareForAnimationChange(EDir::DOWN);
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      {
          movement.x -= PlayerSpeed;
          prepareForAnimationChange(EDir::LEFT);
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      {
          movement.x += PlayerSpeed;
          prepareForAnimationChange(EDir::RIGHT);
      }
      
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && shootPossibility)
      {
          shootPossibility = false;
          shoot();
      }


      if(movement != sf::Vector2f(0.f,0.f))
      {
        sprite.move(movement * deltaTime.asSeconds());
        const auto overlappedActor = Game::tryToOverlap(this);

        if(overlappedActor != "")
        {
          if(overlappedActor == "InvisibleWall" || overlappedActor == "Brick")
          {
            sprite.move(-(movement * deltaTime.asSeconds()));
          }
        }
        
      }
}

void Player::prepareForAnimationChange(EDir dir)
{
  if(this->dir != dir)
  {
     this->dir = dir;
     currFrameCounter = needFrameCounter;
  }
}

void Player::shoot()
{
      sf::Vector2f pos = sprite.getPosition();
      //4.5 it's width / 2 of bullet
      //Left case where handeled cause of bugs (+5.f)
      switch (dir)
      {
        case EDir::UP:
        pos += sf::Vector2f(sprite.getGlobalBounds().width / 2.f - 4.5f, -13.f);
        break;

        case EDir::DOWN:
        pos += sf::Vector2f(sprite.getGlobalBounds().width / 2.f + 4.5f, sprite.getGlobalBounds().height / 2.f + 33.f);
        break;

        case EDir::LEFT:
        pos += sf::Vector2f(-13.f, sprite.getGlobalBounds().height / 2 + 4.5f + 5.f);
        break;

        case EDir::RIGHT:
        pos += sf::Vector2f(sprite.getGlobalBounds().width + 13.f, sprite.getGlobalBounds().height / 2 - 4.5f);
        break;
      }

      Game::createBullet(300.f,pos,dir);
}

bool Player::isMoving() const noexcept
{
   return sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

void Player::render(sf::RenderWindow& window)
{ 
  if(isMoving())
  {
    if(currFrameCounter == needFrameCounter)
    {
          sprite.setTextureRect(drawSprites[dir].get());
          currFrameCounter = 0;
    }
    else
    {
          currFrameCounter += 1;
    }

  }

  window.draw(sprite);
}

void Player::removeImpl()
{

}
