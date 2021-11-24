#include "Zombie.hpp"
#include <ostream>
#include <sstream>

void setZombieNames(Zombie *zombieHorde, int n, std::string name)
{
  for (int i = 0; i < n; ++i)
  {
    std::stringstream zombieName;
    zombieName << name << i;
    zombieHorde[i].setName(zombieName.str());
  }
}

Zombie*
zombieHorde(int N, std::string name)
{
  Zombie* zombieHorde = new Zombie[N];
  setZombieNames(zombieHorde, N, name);
  return zombieHorde;
}