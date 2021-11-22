#include "IODevice.hpp"
#include "PhoneBook.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <string>

class PhoneBookTest
{
public:
  PhoneBookTest()
    : phoneBook(ioDevice)
  {}
  void createOneContact()
  {
    ioDevice.setNextInput("NameBiggerThanTenChars", 0);
    ioDevice.setNextInput("Bond", 1);
    ioDevice.setNextInput("Jammy", 2);
    ioDevice.setNextInput("99999999999", 3);
    ioDevice.setNextInput("I hate bugs", 4);
    phoneBook.add();
    ioDevice.resetOutput();
  }
  MockIODevice ioDevice;
  PhoneBook phoneBook;
};

TEST_CASE_METHOD(PhoneBookTest, "Exit")
{
  phoneBook.exit();
}

TEST_CASE_METHOD(PhoneBookTest, "Add new contact")
{
  const Contact expectedContact = Contact(
    "NameBiggerThanTenChars", "Bond", "Jammy", "99999999999", "I hate bugs");

  createOneContact();

  const Contact& actualContact = phoneBook.getContact(0);
  CHECK(expectedContact == actualContact);
  CHECK(phoneBook.getNumInitializedContacts() == 1);
}

class FullPhoneBookTest : public PhoneBookTest
{
public:
  FullPhoneBookTest()
  {
    for (int i = 0; i < 8; ++i) {
      ioDevice.setNextInput("Maria", 0);
      ioDevice.setNextInput("Santos", 1);
      ioDevice.setNextInput("mari", 2);
      ioDevice.setNextInput("12345678", 3);
      ioDevice.setNextInput("I love tests", 4);
      phoneBook.add();
    }
  }
  void createUserInput()
  {
    ioDevice.setNextInput("NameBiggerThanTenChars", 0);
    ioDevice.setNextInput("Bond", 1);
    ioDevice.setNextInput("Jammy", 2);
    ioDevice.setNextInput("99999999999", 3);
    ioDevice.setNextInput("I hate bugs", 4);
  }
};

TEST_CASE_METHOD(FullPhoneBookTest, "Add 9 contacts, check if restart from 0")
{
  const Contact expectedContact = Contact(
    "NameBiggerThanTenChars", "Bond", "Jammy", "99999999999", "I hate bugs");

  createUserInput();
  phoneBook.add();

  const Contact& actualContact = phoneBook.getContact(0);
  CHECK(expectedContact == actualContact);
  CHECK(phoneBook.getNumInitializedContacts() == 8);
}

TEST_CASE_METHOD(PhoneBookTest, "Search Empty PhoneBook")
{
  phoneBook.search();
  CHECK(ioDevice.getOutput() == "PhoneBook is empty\n");
}

TEST_CASE_METHOD(PhoneBookTest, "Search Invalid Option")
{
  createOneContact();
  ioDevice.setNextInput("9", 0);
  phoneBook.search();
  CHECK(ioDevice.getOutput() ==
	"|     Index|First Name| Last Name|  Nickname|\n|         "
	"0|NameBigge.|      Bond|     Jammy|\nInvalid Option\n");
}

TEST_CASE_METHOD(PhoneBookTest, "Search Valid Option")
{
  createOneContact();
  ioDevice.setNextInput("0", 0);
  phoneBook.search();
  CHECK(
    ioDevice.getOutput() ==
    "|     Index|First Name| Last Name|  Nickname|\n|         0|NameBigge.|    "
    "  Bond|     Jammy|\nNameBiggerThanTenChars\nBond\nJammy\n99999999999\nI "
    "hate bugs\n\n");
}
