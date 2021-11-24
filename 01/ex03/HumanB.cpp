#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
  : Human(name)
  , weapon(NULL)
{}

void
HumanB::setWeapon(Weapon* newWeapon)
{
  weapon = newWeapon;
}

void
HumanB::attack() const
{
  if (weapon)
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
  else
    std::cout << name << " doesn't have a weapon " << std::endl;
}

Weapon*
HumanB::getWeapon()
{
  return weapon;
}
