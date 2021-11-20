#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "IODevice.hpp"

class Contact
{
public:
  Contact();
  Contact(std::string firstName,
	  std::string lastName,
	  std::string nickname,
	  std::string phoneNumber,
	  std::string darkestSecret);
  const std::string &getFirstName();
  const std::string &getLastName();
  const std::string &getNickame();
  const std::string &getPhoneNumber();
  const std::string &getSecret();

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};

class PhoneBook
{
public:
  PhoneBook(IODevice& ioDevice);
  void exit();
  void add();
  const Contact& getContact(int index);

private:
  typedef Contact Contacts[8];
  const int maxContacts;
  int nextContactIndex;

  IODevice& ioDevice;
  Contacts contacts;
};

#endif