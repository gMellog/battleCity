#include <Game.h>
#include <iostream>

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application")
, TimePerFrame{sf::seconds(1.f/60.f)}, wall{sf::FloatRect(0.f,0.f,10.f,480.f)},
wall1{sf::FloatRect(0.f,0.f,640.f,10.f)},wall2{sf::FloatRect(630.f,0.f,10.f,480.f)},wall3{sf::FloatRect(0.f,470.f,640.f,10.f)},
player{}
{

}
void Game::run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (mWindow.isOpen())
  {
      processEvents();
      timeSinceLastUpdate += clock.restart();
      while(timeSinceLastUpdate > TimePerFrame)
      {
        timeSinceLastUpdate -= TimePerFrame;
        processEvents();
        update(TimePerFrame);
      }
      
      render();
  }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch(event.type)
        {
          case sf::Event::KeyPressed:
              player.handleInput(event.key.code, true);
              break;
          
          case sf::Event::KeyReleased:
              player.handleInput(event.key.code, false);
              break;
          
          case sf::Event::Closed:
              mWindow.close();
              break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
  player.Tick(deltaTime);
}

void Game::render()
{
  mWindow.clear();
  player.render(mWindow);
  mWindow.display();
}

Game& Game::get()
{
  static Game game;
  return game;
}

std::vector<ICollisionable*> Game::getCollisionables()
{
  std::vector<ICollisionable*> r_v;
  r_v.push_back(&wall);
  r_v.push_back(&wall1);
  r_v.push_back(&wall2);
  r_v.push_back(&wall3);
  return r_v;
}

