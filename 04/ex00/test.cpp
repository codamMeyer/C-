#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

class AnimalTest : public ::testing::Test
{
public:
  void resetOutput()
  {
    os.str("");
    os.clear();
  };
  std::ostringstream os;
};

TEST_F(AnimalTest, SimpleMakeSoundForAnimal)
{
  Animal genericAnimal(os);

  resetOutput();
  genericAnimal.makeSound();
  EXPECT_EQ(os.str(), "");
}

TEST_F(AnimalTest, simpleDog)
{
  Dog dog(os);

  resetOutput();
  dog.makeSound();
  EXPECT_EQ(os.str(), "Woof Woof\n");
}

TEST_F(AnimalTest, simpleCat)
{
  Cat cat(os);

  resetOutput();
  cat.makeSound();
  EXPECT_EQ(os.str(), "Meaw Meaw\n");
}

TEST_F(AnimalTest, animalSliced)
{
  Dog dog(os);
  Animal animalSliced = dog;

  resetOutput();
  animalSliced.makeSound();

  EXPECT_EQ(os.str(), "");
}

TEST_F(AnimalTest, animalMakeSoundCorrect)
{
  Animal* animalDog = new Dog(os);
  Animal* animalCat = new Cat(os);

  resetOutput();
  animalDog->makeSound();

  EXPECT_EQ(os.str(), "Woof Woof\n");

  resetOutput();
  animalCat->makeSound();
  EXPECT_EQ(os.str(), "Meaw Meaw\n");

  delete animalDog;
  delete animalCat;
}
