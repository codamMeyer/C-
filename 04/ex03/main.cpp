#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

int
main()
{
  AMateria* ice = new Ice();
  std::cout << "\n\ntype is: " << ice->getType() << "\n\n";
  delete ice;

  AMateria* cure = new Cure();
  std::cout << "\n\ntype is: " << cure->getType() << "\n\n";
  delete cure;
  //   IMateriaSource* src = new MateriaSource();
  //   src->learnMateria(new Ice());
  //   src->learnMateria(new Cure());
  //   ICharacter* me = new Character("me");
  //   AMateria* tmp;
  //   tmp = src->createMateria("ice");
  //   me->equip(tmp);
  //   tmp = src->createMateria("cure");
  //   me->equip(tmp);
  //   ICharacter* bob = new Character("bob");
  //   me->use(0, *bob);
  //   me->use(1, *bob);
  //   delete bob;
  //   delete me;
  //   delete src;
  //   return 0;
}