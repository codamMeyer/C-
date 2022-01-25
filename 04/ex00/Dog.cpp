#include "Dog.hpp"

Dog::Dog()
  : Animal()
{
  type = "Dog";
  os << "Dog default constructor called.\n";
}

Dog::Dog(std::ostream& os)
  : Animal(os)
{
  type = "Dog";
  os << "Dog default constructor called.\n";
}

Dog::Dog(const Dog& other)
  : Animal(other)
{
  type = other.type;
  os << "Dog copy constructor called.\n";
}

Dog::~Dog()
{
  os << "Dog destructor called.\n";
}

void
Dog::makeSound() const
{
  os << "Woof Woof\n";
}
