#include <Player.h>
#include <Game.h>
#include <iostream>

Player::Player()
{
  currKey = sf::Keyboard::Key::Unknown;
  currFrameCounter = 0;
  needFrameCounter = 2000;
  PlayerSpeed = 150.f;
  if(!texture.loadFromFile("media/playerSprites.png"))
  {

  }
  else
  {
    sprite.setTexture(texture);
    sprite.setPosition(500.f, 400.f);

    DrawSprite up{sf::IntRect(78,40,39,40),  sf::IntRect(117,40,40,40)};
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

bool Player::isPossibleOverlap(const sf::Sprite& sprite) const noexcept
{
    return true;
}

void Player::Tick(sf::Time deltaTime)
{
    if(isMoving())
    {
      sf::Vector2f movement(0.f, 0.f);

      switch (dir)
      {
        case EDir::UP:
        movement.y -= PlayerSpeed;
        break;

        case EDir::DOWN:
        movement.y += PlayerSpeed;
        break;

        case EDir::LEFT:
        movement.x -= PlayerSpeed;
        break;

        case EDir::RIGHT:
        movement.x += PlayerSpeed;
        break;
      }

      auto& game = Game::get();
      auto actors = game.getAllActors();
      auto it = std::find(actors.begin(),actors.end(), this);
      if(it != actors.end())
      {
        actors.erase(it);
      }
      
      sprite.move(movement * deltaTime.asSeconds());
      for(const auto i : actors)
      {
        if(!i->isPossibleOverlap(sprite))
        {
          sprite.move(-(movement * deltaTime.asSeconds()));
        }
      }
    }
}

void Player::handleInput(sf::Keyboard::Key key, 
                              bool isPressed)
{

      std::cout << "handleInput key: " << key << " pressed: " << std::boolalpha << isPressed << std::endl;
      if(isPressed && isMoveKey(key) && currKey != key)
      {
            currFrameCounter = needFrameCounter;
      }

      currKey = key;

      if (key == sf::Keyboard::W)
      {
          dir = EDir::UP;
      }
      else if (key == sf::Keyboard::S)
      {
          dir = EDir::DOWN;
      }
      else if (key == sf::Keyboard::A)
      {
          dir = EDir::LEFT;
      }
      else if (key == sf::Keyboard::D)
      {
          dir = EDir::RIGHT;
      }
      else if (key == sf::Keyboard::F)
      {
          shoot();
      }

      if(!isPressed && isMoveKey(currKey) && currKey == key)
      {
           currKey = sf::Keyboard::Unknown;
      }
}

void Player::shoot()
{
      sf::Vector2f pos = sprite.getPosition();
      
      pos += sf::Vector2f(sprite.getGlobalBounds().width / 2.f - 4.5f, -50.f);
      // switch (dir)
      // {
      //   case EDir::UP:
      //   movement.y -= PlayerSpeed;
      //   break;

      //   case EDir::DOWN:
      //   movement.y += PlayerSpeed;
      //   break;

      //   case EDir::LEFT:
      //   movement.x -= PlayerSpeed;
      //   break;

      //   case EDir::RIGHT:
      //   movement.x += PlayerSpeed;
      //   break;
      // }

      Game::createBullet(pos,dir);
}

bool Player::isMoveKey(sf::Keyboard::Key key) const noexcept
{
  return  key == sf::Keyboard::W ||
          key == sf::Keyboard::A ||
          key == sf::Keyboard::S ||
          key == sf::Keyboard::D;
}

bool Player::isMoving() const noexcept
{
   return isMoveKey(currKey);
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
