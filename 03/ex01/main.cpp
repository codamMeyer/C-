#include "ScavTrap.hpp"
#include <iostream>

int
main()
{
  const int amout = 2;
  ScavTrap A;
  ScavTrap B("Buddy");
  ScavTrap C;

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
  C.guardGate();

  std::cout << std::endl;
}