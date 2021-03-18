#pragma once
#include <Tickable.h>
#include <map>
#include <iostream>

struct Player : ITickable
{
  public:
           Player();
      void handleInput(sf::Keyboard::Key key, 
                              bool isPressed);
      void Tick(sf::Time deltaTime) override;
      void render(sf::RenderWindow& window);

  private:

      struct DrawSprite
      {
        DrawSprite(const sf::IntRect& areaA = sf::IntRect(), const sf::IntRect& areaB = sf::IntRect())
        :
        first{false},
        _areaA{areaA},
        _areaB{areaB}
        {

        }

        sf::IntRect get() const noexcept
        {
          first = !first;
          return first ? _areaA : _areaB;
        }

        private:
          mutable bool first;
          sf::IntRect _areaA;
          sf::IntRect _areaB;
      };

      sf::Keyboard::Key currKey;
      std::map<std::string, DrawSprite> mDrawSprites;
      std::string currDir;
      unsigned int currFrameCounter;
      unsigned int needFrameCounter;
      float PlayerSpeed;
      sf::Texture texture;
      sf::Sprite  sprite;
};
