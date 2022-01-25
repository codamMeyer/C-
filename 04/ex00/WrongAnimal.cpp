#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
  : type("Generic WrongAnimal")
  , os(std::cout)
{
  os << "WrongAnimal default constructor called.\n";
}

WrongAnimal::WrongAnimal(std::ostream& os)
  : type("Generic WrongAnimal")
  , os(os)
{
  os << "WrongAnimal user-defined constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
  : type(other.type)
  , os(other.os)
{
  os << "WrongAnimal copy constructor called.\n";
}

WrongAnimal::~WrongAnimal()
{
  os << "WrongAnimal Destructor called.\n";
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
  os << "WrongAnimal Sound\n";
}

const std::string&
WrongAnimal::getType() const
{
  return type;
}