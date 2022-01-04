#include "Ice.hpp"
#include <iostream>

Ice::Ice()
  : AMateria("ice")
{
  std::cout << "Ice Constructor called\n";
}

Ice::Ice(const Ice& other)
  : AMateria(other.type)
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
  return new Ice(*this);
}

void
Ice::use(ICharacter& target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
