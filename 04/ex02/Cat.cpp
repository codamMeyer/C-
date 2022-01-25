#include "Cat.hpp"

Cat::Cat()
  : Animal()
  , brain(new Brain())
{
  type = "Cat";
  os << "Cat default constructor called.\n";
}

Cat::Cat(std::ostream& os)
  : Animal(os)
  , brain(new Brain())
{
  type = "Cat";
  os << "Cat default constructor called.\n";
}

Cat::Cat(const Cat& other)
  : Animal(other)
  , brain(new Brain(*(other.brain)))
{
  type = "Cat";
  os << "Cat copy constructor called.\n";
}

Cat::~Cat()
{
  os << "Cat destructor called.\n";
  delete brain;
}

Cat&
Cat::operator=(const Cat& other)
{
  this->brain = other.brain;

  return *this;
}

void
Cat::think() const
{
  os << brain->getNextIdea();
}

void
Cat::makeSound() const
{
  os << "Meaw Meaw\n";
}
