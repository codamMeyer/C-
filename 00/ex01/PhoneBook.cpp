#include "PhoneBook.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstName,
		 std::string lastName,
		 std::string nickname,
		 std::string phoneNumber,
		 std::string darkestSecret)
  : firstName(firstName)
  , lastName(lastName)
  , nickname(nickname)
  , phoneNumber(phoneNumber)
  , darkestSecret(darkestSecret)
{}
const std::string &Contact::getFirstName() 
{
  return firstName;
}
const std::string &Contact::getLastName() 
{
  return lastName;
}
const std::string &Contact::getNickame() 
{
  return nickname;
}
const std::string &Contact::getPhoneNumber() 
{
  return phoneNumber;
}
const std::string &Contact::getSecret() 
{
  return darkestSecret;
}

PhoneBook::PhoneBook(IODevice& ioDevice)
  : maxContacts(8)
  , nextContactIndex(0)
  , ioDevice(ioDevice)
{}

void
PhoneBook::exit()
{}

void
PhoneBook::add()
{
  std::string firstName = ioDevice.readInputLine();
  std::string lastName = ioDevice.readInputLine();
  std::string nickname = ioDevice.readInputLine();
  std::string phoneNumber = ioDevice.readInputLine();
  std::string darkestSecret = ioDevice.readInputLine();

  contacts[nextContactIndex] =
    Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
  nextContactIndex = (nextContactIndex + 1) % maxContacts;
}

const Contact& PhoneBook::getContact(int index) 
{
  return contacts[index];
}
