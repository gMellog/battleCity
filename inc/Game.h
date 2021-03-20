#pragma once
#include <SFML/Graphics.hpp>
#include <Player.h>
#include <Toolchain.h>

using Actors = std::vector<std::unique_ptr<Actor>>;

class Game
{
  public:
    
     void   run();
     static Game&  
            get();

    std::vector<Actor*> 
            getAllActors();

     static 
     void    createBullet(float speed,const sf::Vector2f& pos, EDir dir);
    
     static
     void    removeActor(Actor* r_actor);
    
     static
     std::string tryToOverlap(Actor* actor);


  private:   
     void   processEvents();
     void   update(sf::Time deltaTime);
     void   render();
     void   handlePlayerInput(sf::Keyboard::Key key, 
                              bool isPressed);
     void   createInvisibleWall(const sf::FloatRect& bounds);

  private:

     Game();
     unsigned int windowWidth;
     unsigned int windowHeight;
     Actors actors;

     sf::RenderWindow mWindow;
     sf::Time TimePerFrame;
     Player* player_ptr;
};
