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
  ClapTrap A("T-REX");
  ScavTrap B("Bob");
  FragTrap C("Buddy");

  std::cout << std::endl;
  std::cout << A;
  performAttack(A, B);
  B.beRepaired(repairAmount);
  B.guardGate();
  std::cout << std::endl;

  performAttack(A, C);
  C.beRepaired(repairAmount);
  C.highFivesGuys();

  std::cout << std::endl;
}