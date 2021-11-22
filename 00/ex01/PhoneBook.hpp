#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "IODevice.hpp"
#include <ostream>

class Contact
{
public:
  Contact();
  Contact(std::string firstName,
	  std::string lastName,
	  std::string nickname,
	  std::string phoneNumber,
	  std::string darkestSecret);
  const std::string& getFirstName() const;
  const std::string& getLastName() const;
  const std::string& getNickame() const;
  const std::string& getPhoneNumber() const;
  const std::string& getSecret() const;
  std::string getFormatedPublicInfo() const;
  bool operator==(const Contact &otherContact) const;

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};

std::ostream &operator<<(std::ostream &os, const Contact &contact);
std::string truncate(std::string str, int size);

class PhoneBook
{
public:
  PhoneBook(IODevice& ioDevice);
  void exit();
  void add();
  void search();
  const Contact& getContact(int index);
  void displayContactInfo(int index);
  int getNumInitializedContacts() const;

private:
  typedef Contact Contacts[8];
  const int maxContacts;
  int nextContactIndex;
  int initializedContacts;

  IODevice& ioDevice;
  Contacts contacts;
  void writeContactsTableHeader();
  void displayAvailableContacts();
};

#endif