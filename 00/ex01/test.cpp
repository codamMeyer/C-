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
  ioDevice.setNextInput("Maria", 0);
  ioDevice.setNextInput("Santos", 1);
  ioDevice.setNextInput("mari", 2);
  ioDevice.setNextInput("12345678", 3);
  ioDevice.setNextInput("I love Vini, but he is annoying", 4);

  phoneBook.add();
  Contact contact = phoneBook.getContact(0);
  CHECK(contact.getFirstName() == "Maria");
  CHECK(contact.getLastName() == "Santos");
  CHECK(contact.getNickame() == "mari");
  CHECK(contact.getPhoneNumber() == "12345678");
  CHECK(contact.getSecret() == "I love Vini, but he is annoying");
}