#include "Zombie.hpp"

int
main()
{
  int numZombies = 10;

  Zombie* zombies = zombieHorde(numZombies, "LittleZombie");
  for (int i = 0; i < numZombies; ++i)
    zombies[i].announce();
  delete [] zombies;
}