#include "ClapTrap.hpp"
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
  ClapTrap clap1("ClapTrap1");
  ClapTrap clap2("ClapTrap2");
  ClapTrap clap3("ClapTrap3");

  performAttack(clap1, clap2);
  clap2.beRepaired(1);
  performAttack(clap2, clap3);
  clap2.beRepaired(1);
  performAttack(clap3, clap1);
  clap2.beRepaired(1);

  std::cout << std::endl;
}