#include <Actor.h>

Actor::Actor()
:
pendingToKill{false}
{

}

void Actor::remove()
{
  pendingToKill = true;
  removeImpl();
}

bool Actor::isPendingToKill() const noexcept
{
  return pendingToKill;
}
