#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"

class Dog : public Animal
{
public:
  Dog();
  Dog(std::ostream& os);
  Dog(const Dog& other);
  ~Dog();

  virtual void makeSound();
};

#endif // DOG_H