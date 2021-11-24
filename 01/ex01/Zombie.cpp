#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name)
  : name(name)
{}

Zombie::~Zombie()
{
  std::cout << name << " was killed\n";
}

void
Zombie::setName(std::string newName)
{
  name = newName;
}

void
Zombie::announce(void) const
{
  std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
