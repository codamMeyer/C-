#include "Zombie.hpp"
#include <ostream>
#include <sstream>

Zombie*
zombieHorde(int N, std::string name)
{
  Zombie* zombies = new Zombie[N];
  for (int i = 0; i < N; ++i)
  {
    std::stringstream zombieName;
    zombieName << name << i;
    zombies[i].setName(zombieName.str());
  }
  return zombies;
}