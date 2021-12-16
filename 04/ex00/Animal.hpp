#ifndef ANIMAL_H
#define ANIMAL_H

#include <ostream>
#include <string>

class Animal
{
public:
  Animal();
  Animal(std::ostream& os);
  Animal(const Animal& other);
  virtual ~Animal();

  Animal& operator=(const Animal& other);
  virtual void makeSound();

protected:
  std::string type;
  std::ostream& os;
};

// class WrongAnimal
// {
// public:
//   WrongAnimal(ODevice& os);
//   WrongAnimal(const WrongAnimal& other);
//   ~WrongAnimal();

//   WrongAnimal& operator=(const WrongAnimal& other);
//   void makeSound();

// protected:
//   std::string type;
//   ODevice& oDevice;
// };

#endif // ANIMAL_H
