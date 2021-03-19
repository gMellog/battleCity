#include <Game.h>
#include <iostream>
#include <Bullet.h>

Game::Game()
:
windowWidth{840}, windowHeight{600}, 
mWindow(sf::VideoMode(windowWidth, windowHeight), "")
, TimePerFrame{sf::seconds(1.f/60.f)},player_ptr{}
{
  actors.reserve(100);

  const auto left_border = sf::FloatRect(0.f,0.f,10.f,windowHeight);
  const auto up_border = sf::FloatRect(0.f,0.f,windowWidth,10.f);
  const auto right_border = sf::FloatRect(windowWidth - 10.f ,0.f,10.f, windowHeight);
  const auto bottom_border = sf::FloatRect(0.f,windowHeight - 10.f,windowWidth,10.f);

  createInvisibleWall(left_border);
  createInvisibleWall(up_border);
  createInvisibleWall(right_border);
  createInvisibleWall(bottom_border);

  auto player = std::make_unique<Player>();
  player_ptr = player.get();
  actors.push_back(std::move(player));

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

void Game::createInvisibleWall(const sf::FloatRect& bounds)
{
    actors.push_back(
      std::make_unique<InvisibleWall>
      (bounds));
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
      std::cout << "hey" << std::endl;
        switch(event.type)
        {
          case sf::Event::KeyPressed:
              player_ptr->handleInput(event.key.code, true);
              break;
          
          case sf::Event::KeyReleased:
              player_ptr->handleInput(event.key.code, false);
              break;
          
          case sf::Event::Closed:
              mWindow.close();
              break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
  for(auto& i : actors)
  {
    i->Tick(deltaTime);
  }

}

void Game::render()
{
  mWindow.clear();
  
  for(auto& i : actors)
  {
    i->render(mWindow);
  }

  mWindow.display();
}

Game& Game::get()
{
  static Game game;
  return game;
}

std::vector<IActor*> Game::getAllActors()
{
  std::vector<IActor*> r_v;
  r_v.reserve(actors.size());

  for(auto& i : actors)
  {
    r_v.push_back(i.get());
  }

  return r_v;
}

void Game::createBullet(const sf::Vector2f& pos, EDir dir)
{
  auto& game = get();
  auto bullet = std::make_unique<Bullet>(pos,dir);
  game.actors.push_back(std::move(bullet));
}
