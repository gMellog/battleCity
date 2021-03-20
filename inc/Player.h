#pragma once
#include <Actor.h>
#include <map>
#include <iostream>
#include <Toolchain.h>

struct Player : Actor
{
  public:
           Player(const sf::Vector2f& pos);
      void handleInput(sf::Keyboard::Key key, 
                              bool isPressed);
      void tick(sf::Time deltaTime) override;
      bool isPossibleOverlap(const sf::FloatRect& area) const noexcept override;
      void render(sf::RenderWindow& window) override;
      void overlap(const std::string& Type) override;
      sf::FloatRect getBounds() const noexcept override;
      std::string getType() const override;


  private:
      void shoot();
      bool isMoving() const noexcept;
      void prepareForAnimationChange(EDir dir);
      void removeImpl() override;

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

      std::array<DrawSprite, 4> drawSprites;
      EDir dir;
      unsigned int currFrameCounter;
      unsigned int needFrameCounter;
      
      bool shootPossibility;
      float currReloadTime;
      float endReloadTime;

    
      float reloadGun;

      float PlayerSpeed;
      sf::Texture texture;
      sf::Sprite  sprite;
};
