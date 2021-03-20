#pragma once
#include <string>
#include <memory>
#include <Actor.h>

struct LevelCreator
{
  LevelCreator(const std::string& levelPath);
  
  std::size_t getWidth() const noexcept;
  std::size_t getHeight() const noexcept;

  std::vector<std::unique_ptr<Actor>>
              getActors() noexcept;

  private:
  std::size_t width;
  std::size_t height;
  std::vector<std::unique_ptr<Actor>>
              actors;

};
