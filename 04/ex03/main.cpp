#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void
printTitle(std::string title)
{
  const std::string color = "\033[1m\033[33m";
  const std::string reset = "\033[0m\n";
  std::cout << color << title << reset;
}

int
main()
{
  printTitle("\nCreating MateriaSource");
  IMateriaSource* src = new MateriaSource();

  printTitle("\nLearn New Materias");
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  printTitle("\nCreate Character");
  ICharacter* me = new Character("me");
  AMateria* tmp;

  printTitle("\nCreate Materias and equipe Character");
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  printTitle("\nCreate new Character");
  ICharacter* bob = new Character("bob");

  printTitle("\nUse Materias");
  me->use(0, *bob);
  me->use(1, *bob);

  printTitle("\nDestroy everything");
  delete bob;
  delete me;
  delete src;
  return 0;
}