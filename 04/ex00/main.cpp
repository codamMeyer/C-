#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int
main()
{

  const Animal* meta = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  std::cout << "\n";
  std::cout << dog->getType() << " makes: ";
  dog->makeSound();
  std::cout << std::endl;

  std::cout << cat->getType() << " makes: ";
  cat->makeSound();
  std::cout << std::endl;

  std::cout << meta->getType() << " makes: ";
  meta->makeSound();
  std::cout << "\n\n";

  delete meta;
  delete dog;
  delete cat;

  std::cout << "\n\n";
  std::cout << "WrongAnimal example:\n";

  WrongAnimal* wrongCat = new WrongCat();

  std::cout << wrongCat->getType() << " makes: ";
  wrongCat->makeSound();
  std::cout << "\n\n";

  delete wrongCat;
}