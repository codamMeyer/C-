#include "Animal.hpp"

#include <iostream>

Animal::Animal()
  : type("Animal")
  , os(std::cout)
{
  os << "Default constructor of Animal called.\n";
}

Animal::Animal(std::ostream& os)
  : type("Animal")
  , os(os)
{
  os << "User-defined constructor of Animal called.\n";
}

Animal::Animal(const Animal& other)
  : type(other.type)
  , os(other.os)
{
  os << "Copy constructor of Animal called.\n";
}

Animal::~Animal()
{
  os << "Desstructor of Animal called.\n";
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

void
Animal::think() const
{}

const std::string&
Animal::getType() const
{
  return type;
}