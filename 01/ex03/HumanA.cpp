#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

Human::Human(std::string name)
  : name(name)
{}

HumanA::HumanA(std::string name, Weapon& weapon)
  : Human(name)
  , weapon(weapon)
{}

void
HumanA::attack() const
{
  std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}

const std::string& HumanA::getWaponType() const
{
  return weapon.getType();
}
