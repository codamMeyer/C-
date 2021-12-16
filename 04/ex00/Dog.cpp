#include "Dog.hpp"

Dog::Dog(ODevice& os)
  : Animal(os)
{
  type = "Dog";
  oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
}

Dog::Dog(const Dog& other)
  : Animal(other)
{
  type = "Dog";
  oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
}

Dog::~Dog()
{
  type = "Dog";
  oDevice.writeOutputLine("Default constructor of " + type + " called.\n");
}

void
Dog::makeSound()
{
  oDevice.writeOutputLine("Woof Woof\n");
}
