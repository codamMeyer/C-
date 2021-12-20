#include "ScavTrap.hpp"
#include <iostream>

void
performAttack(ScavTrap& from, ScavTrap& to)
{
  from.attack(to.getName());
  to.takeDamage(from.getAttackDamage());
  std::cout << to << std::endl;
}

int
main()
{
  const int repairAmount = 5;
  ScavTrap scav1("ScavTrap1");
  ScavTrap scav2("ScavTrap2");
  ScavTrap scav3("ScavTrap3");

  scav3 = scav2;
  std::cout << std::endl;
  std::cout << scav1;
  performAttack(scav1, scav2);
  scav2.beRepaired(repairAmount);
  scav2.guardGate();
  std::cout << std::endl;

  performAttack(scav1, scav3);
  scav3.beRepaired(repairAmount);
  scav3.guardGate();

  std::cout << std::endl;
}