#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int
main()
{
  const Animal* meta = new Animal();
  const Dog* dog = new Dog();
  const Cat* cat = new Cat();
  const Cat copyCat(*cat);

  for (int i = 0; i < 5; ++i) {
    std::cout << "😺💭 cat: " << cat->think() << std::endl;
    std::cout << "😹💭 copyCat: " << copyCat.think() << std::endl;
    std::cout << "🐶💭 dog: " << dog->think() << std::endl;
  }
  delete meta;
  delete dog;
  delete cat;
}