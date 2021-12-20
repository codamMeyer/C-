#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void
performAttack(ClapTrap& from, ClapTrap& to)
{
  from.attack(to.getName());
  to.takeDamage(from.getAttackDamage());
  std::cout << to << std::endl;
}

int
main()
{
  DiamondTrap diamond("DiamondTrap");
  FragTrap frag("FragTrap");

  std::cout << "\n\n";
  diamond.whoAmI();
  std::cout << "\n\n";
  diamond.highFivesGuys();
  diamond.guardGate();
  diamond.attack(frag.getName());
  frag.takeDamage(diamond.getAttackDamage());
  frag.attack(diamond.getName());
  diamond.takeDamage(frag.getAttackDamage());
  std::cout << diamond << std::endl;
  diamond.beRepaired(5);
  std::cout << diamond << std::endl;

  std::cout << diamond << std::endl;
  std::cout << frag << std::endl;
}