#include <Player.h>
#include <Game.h>
#include <iostream>

Player::Player()
{
  currKey = sf::Keyboard::Key::Unknown;
  currFrameCounter = 0;
  needFrameCounter = 2000;
  PlayerSpeed = 50.f;
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

    mDrawSprites.insert(std::make_pair("Up", up));
    mDrawSprites.insert(std::make_pair("Down", down));
    mDrawSprites.insert(std::make_pair("Left", left));
    mDrawSprites.insert(std::make_pair("Right", right));

    currDir = "";
    sprite.setTextureRect(mDrawSprites["Up"].get());
  }
}

void Player::Tick(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
  
    if (currDir == "Up")
    {
      movement.y -= PlayerSpeed;
    }
    else if (currDir == "Down")
    {
      movement.y += PlayerSpeed;
    }
    else if (currDir == "Left")
    {
      movement.x -= PlayerSpeed;
    }
    else if (currDir == "Right")
    {
      movement.x += PlayerSpeed;
    }

    auto& game = Game::get();
    sprite.move(movement * deltaTime.asSeconds());

    const auto collisionables = game.getCollisionables();

    for(const auto i : collisionables)
    {
      if(!i->isPossibleOverlap(sprite))
      {
        sprite.move(-(movement * deltaTime.asSeconds()));
      }
    }
}

void Player::handleInput(sf::Keyboard::Key key, 
                              bool isPressed)
{
      if(isPressed && currKey != key)
      {
            currKey = key;
            currFrameCounter = needFrameCounter;
      }

      if (key == sf::Keyboard::W)
      {
          currDir = isPressed ? "Up" : "";
      }
      else if (key == sf::Keyboard::S)
      {
          currDir = isPressed ? "Down" : "";
      }
      else if (key == sf::Keyboard::A)
      {
           currDir = isPressed ? "Left" : "";
      }
      else if (key == sf::Keyboard::D)
      {
          currDir = isPressed ? "Right" : "";
      }

      if(!isPressed)
      {
           currKey = sf::Keyboard::Unknown;
      }
}

void Player::render(sf::RenderWindow& window)
{ 
  if(currDir != "")
  {
    if(currFrameCounter == needFrameCounter)
    {
          sprite.setTextureRect(mDrawSprites[currDir].get());
          currFrameCounter = 0;
    }
    else
    {
          currFrameCounter += 1;
    }

  }

  window.draw(sprite);
}
