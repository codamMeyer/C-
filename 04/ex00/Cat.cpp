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
Cat::makeSound()
{
  os << "Meaw Meaw\n";
}

// WrongCat::WrongCat(ODevice& os)
//   : WrongAnimal(os)
// {
//   type = "WrongCat";
//   oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
// }

// WrongCat::WrongCat(const WrongCat& other)
//   : WrongAnimal(other)
// {
//   type = "WrongCat";
//   oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
// }

// WrongCat::~WrongCat()
// {
//   type = "WrongCat";
//   oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
// }

// void
// WrongCat::makeSound()
// {
//   oDevice.writeOutputLine("Meaw Meaw\n");
// }
