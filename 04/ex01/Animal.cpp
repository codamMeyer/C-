#include "Animal.hpp"

#include <iostream>

Animal::Animal()
  : type("Generic Animal")
  , os(std::cout)
{
  os << "Default constructor of " << type << " called.\n";
}

Animal::Animal(std::ostream& os)
  : type("Generic Animal")
  , os(os)
{
  os << "User-defined constructor of " << type << " called.\n";
}

Animal::Animal(const Animal& other)
  : type(other.type)
  , os(other.os)
{
  os << "Copy constructor of " << type << " called.\n";
}

Animal::~Animal()
{
  os << "Desstructor of " << type << " called.\n";
}

Animal&
Animal::operator=(const Animal& other)
{
  this->type = other.type;
  return *this;
}

void
Animal::makeSound() const
{}

const std::string&
Animal::getType() const
{
  return type;
}