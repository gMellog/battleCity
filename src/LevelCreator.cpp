#include <LevelCreator.h>
#include <fstream>
#include <Brick.h>
#include <Stone.h>
#include <Base.h>
#include <Player.h>

LevelCreator::LevelCreator(const std::string& levelPath)
{
   std::ifstream levelFile(levelPath);
   
   std::string line;
   std::vector<std::string>
               lines;

   while(std::getline(levelFile, line))
   {
      lines.push_back(std::move(line));
   }

   height = lines.size() - 2;
   std::size_t i{};
   for(; lines[0][i] != '\0'; ++i)
   {

   }

   width = i - 2;
   actors.reserve(100);
  
  i = 1;

  bool baseCreated = false;

  for(; i < lines.size() - 1; ++i)
  {
       for(std::size_t j{}; lines[i][j] != '\0'; ++j)
       {
          std::unique_ptr<Actor> actor;
          sf::Vector2f pos{j * 24.f, (i - 1) * 24.f};

          if(lines[i][j] == '1')
          {
            actor = std::make_unique<Brick>(pos);
          }
          else if(lines[i][j] == '2')
          {
            actor = std::make_unique<Stone>(pos);
          }
          else if(lines[i][j] == '3' && !baseCreated)
          {
            baseCreated = true;
            actor = std::make_unique<Base>(pos);
          }
          else if(lines[i][j] == '4')
          {
             actor = std::make_unique<Player>(pos);
          }

        if(actor)
        {
          actors.push_back(std::move(actor));
        }

       }
  }


}
  
std::size_t LevelCreator::getWidth() const noexcept
{
    return width * 24;
}

std::size_t LevelCreator::getHeight() const noexcept
{
    return height * 24;
}

std::vector<std::unique_ptr<Actor>>
            LevelCreator::getActors() noexcept
{


    

    return std::move(actors);
}
