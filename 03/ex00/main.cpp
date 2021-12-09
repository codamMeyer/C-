#include "ClapTrap.hpp"
#include <iostream>

int
main()
{
  const int amout = 2;
  ClapTrap A("Mike");
  ClapTrap B("Buddy");
  ClapTrap C("Jake");

  C = B;
  std::cout << std::endl;
  std::cout << A;
  A.attack("Monster");
  A.takeDamage(amout);
  std::cout << A;
  A.beRepaired(amout);

  std::cout << std::endl;
  std::cout << B;
  B.attack("T-REX");
  B.takeDamage(amout);
  std::cout << B;
  B.beRepaired(amout);

  std::cout << std::endl;
  std::cout << C;
  C.attack("Alien");
  C.takeDamage(amout);
  std::cout << C;
  C.beRepaired(amout);

  std::cout << std::endl;
}