#include "Dog.hpp"

Dog::Dog()
  : Animal()
  , brain(new Brain())
{
  type = "Dog";
  os << "Dog default constructor called.\n";
}

Dog::Dog(std::ostream& os)
  : Animal(os)
  , brain(new Brain())

{
  type = "Dog";
  os << "Dog default constructor called.\n";
}

Dog::Dog(const Dog& other)
  : Animal(other)
  , brain(new Brain(*(other.brain)))
{
  type = "Dog";
  os << "Dog copy constructor called.\n";
}

Dog::~Dog()
{
  type = "Dog";
  os << "Dog destructor called.\n";
  delete brain;
}

Dog&
Dog::operator=(const Dog& other)
{
  this->type = other.type;
  this->brain = other.brain;
  return *this;
}

void
Dog::think() const
{
  os << brain->getNextIdea();
}

void
Dog::makeSound() const
{
  os << "Woof Woof\n";
}
