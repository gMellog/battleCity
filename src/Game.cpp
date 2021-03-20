#include <Game.h>
#include <iostream>
#include <Bullet.h>
#include <LevelCreator.h>
#include <InvisibleWall.h>

Game::Game()
:
TimePerFrame{sf::seconds(1.f/60.f)},player_ptr{}
{

  LevelCreator levelCreator{"media/introLevelLayout"};
  mWindow.create(sf::VideoMode(
    levelCreator.getWidth(),
    levelCreator.getHeight()), "");

  actors = std::move(levelCreator.getActors());
 
  const auto left_border = sf::FloatRect(0.f,0.f,0.001f,levelCreator.getHeight());
  const auto up_border = sf::FloatRect(0.f,0.f,levelCreator.getWidth(),0.001f);
  const auto right_border = sf::FloatRect(levelCreator.getWidth() - 0.001f ,0.f,0.001f, levelCreator.getHeight());
  const auto bottom_border = sf::FloatRect(0.f,levelCreator.getHeight() - 0.001f,levelCreator.getWidth(),0.001f);
  createInvisibleWall(left_border);
  createInvisibleWall(up_border);
  createInvisibleWall(right_border);
  createInvisibleWall(bottom_border);


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
      
      for(auto it = actors.begin(); it != actors.end(); ++it)
      {
        if(*it)
        {
                if((*it)->isPendingToKill())
                {
                  it = actors.erase(it);
                  if(it == actors.end())
                  {
                    break;
                  }
                }
        }
      }

  }

}

std::string Game::tryToOverlap(Actor* actor)
{
    std::string r;
    auto& game = Game::get();
    auto actors = game.getAllActors();
    auto it = std::find(actors.begin(),actors.end(), actor);
    if(it != actors.end())
    {
        actors.erase(it);
    }
        
    for(const auto i : actors)
    {
          if(i->isPossibleOverlap(actor->getBounds()))
          {
            i->overlap(actor->getType());
            r = i->getType();
            break;
          }
    }

    return r;
}

void Game::removeActor(Actor* r_actor)
{
  auto& game = get();
   auto it = std::find_if(game.actors.begin(), game.actors.end(),
   [r_actor](std::unique_ptr<Actor>& actor)
   {
    return actor.get() == r_actor;
   }
   );

   if(it != game.actors.end())
   {
     (*it)->remove();
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            mWindow.close();
        }
    }
}

void Game::update(sf::Time deltaTime)
{

  for(auto& i : actors)
  {
    i->tick(deltaTime);
  }

}

void Game::render()
{
  mWindow.clear();
  
  for(auto& i : actors)
  {
    if(i)
    {
      i->render(mWindow);
    }
  }

  mWindow.display();
}

Game& Game::get()
{
  static Game game;
  return game;
}

std::vector<Actor*> Game::getAllActors()
{
  std::vector<Actor*> r_v;
  r_v.reserve(actors.size());

  for(auto& i : actors)
  {
    r_v.push_back(i.get());
  }

  return r_v;
}

void Game::createBullet(float speed, const sf::Vector2f& pos, EDir dir)
{
  auto& game = get();
  auto bullet = std::make_unique<Bullet>(speed,pos,dir);
  game.actors.push_back(std::move(bullet));
}
