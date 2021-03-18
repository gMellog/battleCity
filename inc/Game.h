#pragma once
#include <SFML/Graphics.hpp>
#include <InvisibleWall.h>
#include <Player.h>

class Game
{
  public:
     void   run();
     static Game&  get();

     std::vector<ICollisionable*>
            getCollisionables();
  private:   
     void   processEvents();
     void   update(sf::Time deltaTime);
     void   render();
     void   handlePlayerInput(sf::Keyboard::Key key, 
                              bool isPressed);
  private:

     Game();
     InvisibleWall wall;
     InvisibleWall wall1;
     InvisibleWall wall2;
     InvisibleWall wall3;

     sf::RenderWindow mWindow;
     sf::Time TimePerFrame;
     Player player;
};
