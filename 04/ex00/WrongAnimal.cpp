#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
  : type("Generic WrongAnimal")
  , os(std::cout)
{
  os << "Default constructor of " << type << " called.\n";
}

WrongAnimal::WrongAnimal(std::ostream& os)
  : type("Generic WrongAnimal")
  , os(os)
{
  os << "User-defined constructor of " << type << " called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
  : type(other.type)
  , os(other.os)
{
  os << "Copy constructor of " << type << " called.\n";
}

WrongAnimal::~WrongAnimal()
{
  os << "Desstructor of " << type << " called.\n";
}

WrongAnimal&
WrongAnimal::operator=(const WrongAnimal& other)
{
  this->type = other.type;
  return *this;
}

void
WrongAnimal::makeSound() const
{
  os << "Wrong Animal Sound\n";
}

const std::string&
WrongAnimal::getType() const
{
  return type;
}