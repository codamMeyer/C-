#include "WrongCat.hpp"

WrongCat::WrongCat()
  : WrongAnimal()
{
  type = "WrongCat";
  os << "Default constructor of " << type << " called.\n";
}

WrongCat::WrongCat(std::ostream& os)
  : WrongAnimal(os)
{
  type = "WrongCat";
  os << "User-defined constructor of " << type << " called.\n";
}

WrongCat::WrongCat(const WrongCat& other)
  : WrongAnimal(other)
{
  type = "WrongCat";
  os << "Default constructor of " << type << " called.\n";
}

WrongCat::~WrongCat()
{
  type = "WrongCat";
  os << "Default constructor of " << type << " called.\n";
}

void
WrongCat::makeSound() const
{
  os << "Meaw Meaw\n";
}