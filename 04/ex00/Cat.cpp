#include "Cat.hpp"

Cat::Cat()
  : Animal()
{
  type = "Cat";
  os << "Default constructor of " << type << " called.\n";
}

Cat::Cat(std::ostream& os)
  : Animal(os)
{
  type = "Cat";
  os << "Default constructor of " << type << " called.\n";
}

Cat::Cat(const Cat& other)
  : Animal(other)
{
  type = "Cat";
  os << "Default constructor of " << type << " called.\n";
}

Cat::~Cat()
{
  type = "Cat";
  os << "Default constructor of " << type << " called.\n";
}

void
Cat::makeSound() const
{
  os << "Meaw Meaw\n";
}