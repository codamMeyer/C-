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

TEST_F(AnimalTest, animalMakeSoundCorrect)
{
  Animal* animalDog = new Dog(os);
  Animal* animalCat = new Cat(os);

  resetOutput();
  animalDog->makeSound();

  EXPECT_EQ(os.str(), "Woof Woof\n");
  resetOutput();
  animalDog->think();
  EXPECT_EQ(os.str(), "Stupid idea number 0");

  resetOutput();
  animalCat->makeSound();
  EXPECT_EQ(os.str(), "Meaw Meaw\n");

  resetOutput();
  animalCat->think();
  EXPECT_EQ(os.str(), "Stupid idea number 0");
  delete animalDog;
  delete animalCat;
}

TEST_F(AnimalTest, animalThinkCorrect)
{
  Animal* animalDog = new Dog(os);
  Animal* animalCat = new Cat(os);

  resetOutput();
  animalDog->think();
  EXPECT_EQ(os.str(), "Stupid idea number 0");

  resetOutput();
  animalCat->think();
  EXPECT_EQ(os.str(), "Stupid idea number 0");
  delete animalDog;
  delete animalCat;
}
