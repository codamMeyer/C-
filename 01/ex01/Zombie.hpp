#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void setName(std::string name);
  void announce(void) const;

private:
  std::string name;
};

Zombie* zombieHorde(int N, std::string name);
#endif // ZOMBIE_H