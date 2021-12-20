#include "Dog.hpp"

Dog::Dog()
  : Animal()
  , brain(new Brain())
{
  type = "Dog";
  os << "Default constructor of " << type << " called.\n";
}

Dog::Dog(std::ostream& os)
  : Animal(os)
  , brain(new Brain())

{
  type = "Dog";
  os << "Default constructor of " << type << " called.\n";
}

Dog::Dog(const Dog& other)
  : Animal(other)
  , brain(new Brain(*(other.brain)))
{
  type = "Dog";
  os << "Default constructor of " << type << " called.\n";
}

Dog::~Dog()
{
  type = "Dog";
  os << "Default constructor of " << type << " called.\n";
  delete brain;
}

Dog&
Dog::operator=(const Dog& other)
{
  this->brain = other.brain;
  return *this;
}

const std::string&
Dog::think() const
{
  return brain->getNextIdea();
}

void
Dog::makeSound() const
{
  os << "Woof Woof\n";
}
