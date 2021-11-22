#include "IODevice.hpp"
#include "PhoneBook.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

class PhoneBookTest
{
public:
  PhoneBookTest()
    : phoneBook(ioDevice)
  {}

  MockIODevice ioDevice;
  PhoneBook phoneBook;
};

TEST_CASE_METHOD(PhoneBookTest, "Exit")
{
  phoneBook.exit();
}

TEST_CASE_METHOD(PhoneBookTest, "Add new contact")
{
  const Contact expectedContact =
    Contact("Maria", "Santos", "mari", "12345678", "I love tests");

  ioDevice.setNextInput("Maria", 0);
  ioDevice.setNextInput("Santos", 1);
  ioDevice.setNextInput("mari", 2);
  ioDevice.setNextInput("12345678", 3);
  ioDevice.setNextInput("I love tests", 4);
  phoneBook.add();

  const Contact &actualContact = phoneBook.getContact(0);
  CHECK(expectedContact == actualContact);
}