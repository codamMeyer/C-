#include "Animal.hpp"

#include <iostream>

Animal::Animal()
  : Animal(std::cout)
{
  os << "Default constructor of " << type << " called.\n";
}

Animal::Animal(std::ostream& os)
  : type("Generic Animal")
  , os(os)
{
  os << "User-defined constructor of " << type << " called.\n";
}

Animal::Animal(const Animal& other)
  : type(other.type)
  , os(other.os)
{
  os << "Copy constructor of " << type << " called.\n";
}

Animal::~Animal()
{
  os << "Desstructor of " << type << " called.\n";
}

Animal&
Animal::operator=(const Animal& other)
{
  this->type = other.type;
  return *this;
}

void
Animal::makeSound()
{}

// WrongAnimal::WrongAnimal(ODevice& os)
//   : type("Generic WrongAnimal")
//   , oDevice(os)
// {
//   oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
// }

// WrongAnimal::WrongAnimal(const WrongAnimal& other)
//   : type(other.type)
//   , oDevice(other.oDevice)
// {
//   oDevice.writeOutputLine("Copy constructor of " + type + " called.\n");
// }

// WrongAnimal::~WrongAnimal()
// {
//   oDevice.writeOutputLine("Desstructor of " + type + " called.\n");
// }

// WrongAnimal&
// WrongAnimal::operator=(const WrongAnimal& other)
// {
//   this->type = other.type;
//   return *this;
// }

// void
// WrongAnimal::makeSound()
// {
//   oDevice.writeOutputLine("Wrong Animal Sound\n");
// }
