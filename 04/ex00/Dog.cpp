#include "Dog.hpp"

Dog::Dog()
  : Animal()
{
  type = "Dog";
  os << "Default constructor of " << type << " called.\n";
}

Dog::Dog(std::ostream& os)
  : Animal(os)
{
  type = "Dog";
  os << "Default constructor of " << type << " called.\n";
}

Dog::Dog(const Dog& other)
  : Animal(other)
{
  type = "Dog";
  os << "Default constructor of " << type << " called.\n";
}

Dog::~Dog()
{
  type = "Dog";
  os << "Default constructor of " << type << " called.\n";
}

void
Dog::makeSound()
{
  os << "Woof Woof\n";
}
