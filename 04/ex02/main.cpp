#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int
main()
{
  // const Animal animal();
  const Dog* dog = new Dog();
  const Cat* cat = new Cat();
  const Cat copyCat(*cat);

  std::cout << "\n\n\nMake them think:\n\n";
  for (int i = 0; i < 5; ++i) {
    std::cout << "😺💭 cat: ";
    cat->think();
    std::cout << std::endl;
    std::cout << "😹💭 copyCat: ";
    copyCat.think();
    std::cout << std::endl;
    std::cout << "🐶💭 dog: ";
    dog->think();
    std::cout << std::endl;
  }
  std::cout << "\n\n";
  delete dog;
  delete cat;

  std::cout << "\n\n\nCreating array of 10 pets\n\n";
  Animal* pets[10];
  for (int i = 0; i < 5; ++i) {
    pets[i] = new Dog();
  }

  for (int i = 5; i < 10; ++i) {
    pets[i] = new Cat();
  }
  std::cout << "\n\n\nDestroying array of pets\n\n";

  for (int i = 0; i < 10; ++i) {
    delete pets[i];
  }
}