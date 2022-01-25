#include "WrongCat.hpp"

WrongCat::WrongCat()
  : WrongAnimal()
{
  type = "WrongCat";
  os << "WrongCat default constructor called.\n";
}

WrongCat::WrongCat(std::ostream& os)
  : WrongAnimal(os)
{
  type = "WrongCat";
  os << "WrongCat user-defined constructor called.\n";
}

WrongCat::WrongCat(const WrongCat& other)
  : WrongAnimal(other)
{
  type = "WrongCat";
  os << "WrongCat copy constructor called.\n";
}

WrongCat::~WrongCat()
{
  type = "WrongCat";
  os << "WrongCat destructor called.\n";
}

void
WrongCat::makeSound() const
{
  os << "Meaw Meaw\n";
}