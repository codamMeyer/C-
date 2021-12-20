#include "ClapTrap.hpp"
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
  const int repairAmount = 5;
  FragTrap frag1("FragTrap1");
  ScavTrap frag2("ScavTrap2");
  FragTrap frag3("FragTrap3");

  frag3 = frag1;
  std::cout << std::endl;
  std::cout << frag1;
  performAttack(frag1, frag2);
  frag2.beRepaired(repairAmount);
  frag2.guardGate();
  std::cout << std::endl;

  performAttack(frag1, frag3);
  frag3.beRepaired(repairAmount);
  frag3.highFivesGuys();

  std::cout << std::endl;
}