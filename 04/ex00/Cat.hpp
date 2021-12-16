#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"

class Cat : public Animal
{
public:
  Cat(ODevice& os);
  Cat(const Cat& other);
  ~Cat();

  virtual void makeSound();
};

class WrongCat : public WrongAnimal
{
public:
  WrongCat(ODevice& os);
  WrongCat(const WrongCat& other);
  ~WrongCat();

  virtual void makeSound();
};

#endif // CAT_H