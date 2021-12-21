#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type)
  : type(type)
{
  std::cout << "AMateria Constructor called\n";
}

AMateria::AMateria(const AMateria&)
{
  std::cout << "AMateria Copy Constructor called\n";
}

AMateria::~AMateria()
{
  std::cout << "AMateria Destructor called\n";
}

AMateria&
AMateria::operator=(const AMateria& other)
{
  type = other.getType();
  return *this;
}

std::string const&
AMateria::getType() const
{
  return type;
}

void
AMateria::use(ICharacter&)
{}