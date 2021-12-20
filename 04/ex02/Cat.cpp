#include "Cat.hpp"

Cat::Cat()
  : Animal()
  , brain(new Brain())
{
  type = "Cat";
  os << "Default constructor of " << type << " called.\n";
}

Cat::Cat(std::ostream& os)
  : Animal(os)
  , brain(new Brain())
{
  type = "Cat";
  os << "Default constructor of " << type << " called.\n";
}

Cat::Cat(const Cat& other)
  : Animal(other)
  , brain(new Brain(*(other.brain)))
{
  type = "Cat";
  os << "Default constructor of " << type << " called.\n";
}

Cat::~Cat()
{
  type = "Cat";
  os << "Destructor of " << type << " called.\n";
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
