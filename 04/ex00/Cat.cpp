#include "Cat.hpp"

Cat::Cat()
  : Animal()
{
  type = "Cat";
  os << "Cat default constructor called.\n";
}

Cat::Cat(std::ostream& os)
  : Animal(os)
{
  type = "Cat";
  os << "Cat default constructor called.\n";
}

Cat::Cat(const Cat& other)
  : Animal(other)
{
  type = "Cat";
  os << "Cat copy constructor called.\n";
}

Cat::~Cat()
{
  type = "Cat";
  os << "Cat destructor called.\n";
}

void
Cat::makeSound() const
{
  os << "Meaw Meaw\n";
}