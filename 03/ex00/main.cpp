#include "ClapTrap.hpp"
#include <iostream>

int
main()
{
  const int amout = 2;
  ClapTrap A;
  ClapTrap B("Buddy");
  ClapTrap C;

  C = B;
  std::cout << std::endl;
  A.attack("Monster");
  A.takeDamage(amout);
  A.beRepaired(amout);

  std::cout << std::endl;
  B.attack("Monster");
  B.takeDamage(amout);
  B.beRepaired(amout);

  std::cout << std::endl;
  C.attack("Monster");
  C.takeDamage(amout);
  C.beRepaired(amout);

  std::cout << std::endl;
}