#include "Animal.hpp"
#include <iostream>

Animal::Animal()
  : type("Animal")
  , os(std::cout)
{
  os << "Animal default constructor called.\n";
}

Animal::Animal(std::ostream& os)
  : type("Animal")
  , os(os)
{
  os << "Animal user-defined constructor called.\n";
}

Animal::Animal(const Animal& other)
  : type(other.type)
  , os(other.os)
{
  os << "Animal copy constructor called.\n";
}

Animal::~Animal()
{
  os << "Animal destructor called.\n";
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