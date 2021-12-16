#include "Animal.hpp"
#include "ODevice.hpp"
#include <iostream>

Animal::Animal(ODevice& os)
  : type("Generic Animal")
  , oDevice(os)
{
  oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
}

Animal::Animal(const Animal& other)
  : type(other.type)
  , oDevice(other.oDevice)
{
  oDevice.writeOutputLine("Copy constructor of " + type + " called.\n");
}

Animal::~Animal()
{
  oDevice.writeOutputLine("Desstructor of " + type + " called.\n");
}

Animal&
Animal::operator=(const Animal& other)
{
  this->type = other.type;
  return *this;
}

WrongAnimal::WrongAnimal(ODevice& os)
  : type("Generic WrongAnimal")
  , oDevice(os)
{
  oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
  : type(other.type)
  , oDevice(other.oDevice)
{
  oDevice.writeOutputLine("Copy constructor of " + type + " called.\n");
}

WrongAnimal::~WrongAnimal()
{
  oDevice.writeOutputLine("Desstructor of " + type + " called.\n");
}

WrongAnimal&
WrongAnimal::operator=(const WrongAnimal& other)
{
  this->type = other.type;
  return *this;
}

void
WrongAnimal::makeSound()
{
  oDevice.writeOutputLine("Wrong Animal Sound\n");
}
