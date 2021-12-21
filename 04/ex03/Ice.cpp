#include "Ice.hpp"
#include <iostream>

Ice::Ice()
  : AMateria("ice")
{
  std::cout << "Ice Constructor called\n";
}

Ice::Ice(const Ice& other)
  : AMateria(other)
{
  std::cout << "Ice Copy Constructor called\n";
}

Ice::~Ice()
{
  std::cout << "Ice Destructor called\n";
}

AMateria*
Ice::clone() const
{
  AMateria* clone = new Ice();
  return clone;
}

void
Ice::use(ICharacter& target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
