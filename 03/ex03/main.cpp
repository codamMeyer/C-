#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void
performAttack(ClapTrap& from, ClapTrap& to)
{
  from.attack(to.getName());
  to.takeDamage(from.getAttackDemage());
  std::cout << to << std::endl;
}

int
main()
{
  DiamondTrap A("T-REX");
  FragTrap B("Beast");

  A.whoAmI();
  A.highFivesGuys();
  A.guardGate();
  A.attack("MONSTEEER");
  A.takeDamage(5);
  std::cout << A << std::endl;
  A.beRepaired(5);
  std::cout << A << std::endl;

  std::cout << A << std::endl;
  std::cout << B << std::endl;
}