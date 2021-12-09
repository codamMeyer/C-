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
  ScavTrap A("T-REX");
  ScavTrap B("Buddy");
  ScavTrap C("Jake");

  C = B;
  std::cout << std::endl;
  std::cout << A;
  performAttack(A, B);
  B.beRepaired(repairAmount);
  B.guardGate();
  std::cout << std::endl;

  performAttack(A, C);
  C.beRepaired(repairAmount);
  C.guardGate();

  std::cout << std::endl;
}