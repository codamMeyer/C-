#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure()
  : AMateria("cure")
{
  std::cout << "Cure Constructor called\n";
}

Cure::Cure(const Cure& other)
  : AMateria(other.type)
{
  std::cout << "Cure Copy Constructor called\n";
}

Cure::~Cure()
{
  std::cout << "Cure Destructor called\n";
}

AMateria*
Cure::clone() const
{
  AMateria* clone = new Cure(*this);
  return clone;
}

void
Cure::use(ICharacter& target)
{
  std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
