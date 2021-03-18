#include <Game.h>

int main()
{
  auto& game = Game::get();
  game.run();

  return 0;
}
