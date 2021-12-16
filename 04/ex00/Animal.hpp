#ifndef ANIMAL_H
#define ANIMAL_H
#include "ODevice.hpp"
#include <ostream>
#include <string>

class Animal
{
public:
  Animal(ODevice& os);
  Animal(const Animal& other);
  ~Animal();

  Animal& operator=(const Animal& other);
  virtual void makeSound() { oDevice.writeOutputLine(""); };

protected:
  std::string type;
  ODevice& oDevice;
};

class WrongAnimal
{
public:
  WrongAnimal(ODevice& os);
  WrongAnimal(const WrongAnimal& other);
  ~WrongAnimal();

  WrongAnimal& operator=(const WrongAnimal& other);
  void makeSound();

protected:
  std::string type;
  ODevice& oDevice;
};

#endif // ANIMAL_H
