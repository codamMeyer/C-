#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "ODevice.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

class AnimalTest : public ::testing::Test
{
public:
  MockODevice oDevice;

protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(AnimalTest, SimpleMakeSoundForAnimal)
{
  Animal genericAnimal(oDevice);

  oDevice.resetOutput();
  genericAnimal.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "");
}

TEST_F(AnimalTest, simpleDog)
{
  Animal genericAnimal(oDevice);
  Dog dog(oDevice);

  oDevice.resetOutput();
  genericAnimal.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "");
  oDevice.resetOutput();
  dog.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "Woof Woof\n");
  genericAnimal = dog;
  oDevice.resetOutput();
  genericAnimal.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "");
}

TEST_F(AnimalTest, simpleCat)
{
  Animal genericAnimal(oDevice);
  Cat cat(oDevice);

  oDevice.resetOutput();
  genericAnimal.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "");
  oDevice.resetOutput();
  cat.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "Meaw Meaw\n");
  genericAnimal = cat;
  oDevice.resetOutput();
  genericAnimal.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "");
}

TEST_F(AnimalTest, WrongCat)
{
  WrongAnimal genericAnimal(oDevice);
  WrongCat cat(oDevice);

  oDevice.resetOutput();
  genericAnimal.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "Wrong Animal Sound\n");
  oDevice.resetOutput();
  cat.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "Meaw Meaw\n");
  genericAnimal = cat;
  oDevice.resetOutput();
  genericAnimal.makeSound();
  EXPECT_EQ(oDevice.getOutput(), "Wrong Animal Sound\n");
}
