#include "PhoneBook.hpp"
#include "IODevice.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

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
const std::string&
Contact::getFirstName() const
{
  return firstName;
}
const std::string&
Contact::getLastName() const
{
  return lastName;
}
const std::string&
Contact::getNickame() const
{
  return nickname;
}
const std::string&
Contact::getPhoneNumber() const
{
  return phoneNumber;
}
const std::string&
Contact::getSecret() const
{
  return darkestSecret;
}

std::string
Contact::getFormatedPublicInfo() const
{
  const int colWidth = 10;
  const char separator = '|';
  std::stringstream ss;

  ss << std::setw(colWidth) << truncate(firstName, colWidth) << separator;
  ss << std::setw(colWidth) << truncate(lastName, colWidth) << separator;
  ss << std::setw(colWidth) << truncate(nickname, colWidth) << separator;
  return ss.str();
}

bool
Contact::operator==(const Contact& otherContact) const
{
  return (firstName == otherContact.firstName &&
	  lastName == otherContact.lastName &&
	  nickname == otherContact.nickname &&
	  phoneNumber == otherContact.phoneNumber &&
	  darkestSecret == otherContact.darkestSecret);
}

std::string
truncate(std::string str, int size)
{
  const int len = str.length();

  if (len > size) {
    str.resize(size - 1);
    str.resize(size, '.');
  }
  return str;
}

std::ostream&
operator<<(std::ostream& os, const Contact& contact)
{
  return os << contact.getFirstName() << "\n"
	    << contact.getLastName() << "\n"
	    << contact.getNickame() << "\n"
	    << contact.getPhoneNumber() << "\n"
	    << contact.getSecret() << "\n";
}

PhoneBook::PhoneBook(IODevice& ioDevice)
  : maxContacts(8)
  , nextContactIndex(0)
  , initializedContacts(-1)
  , ioDevice(ioDevice)
{}

void
PhoneBook::exit()
{}

void
PhoneBook::add()
{
  ioDevice.writeOutputLine("First Name: ");
  std::string firstName = ioDevice.readInputLine();
  ioDevice.writeOutputLine("Last Name: ");
  std::string lastName = ioDevice.readInputLine();
  ioDevice.writeOutputLine("Nickame: ");
  std::string nickname = ioDevice.readInputLine();
  ioDevice.writeOutputLine("Phone Number: ");
  std::string phoneNumber = ioDevice.readInputLine();
  ioDevice.writeOutputLine("Darkest Secret: ");
  std::string darkestSecret = ioDevice.readInputLine();

  contacts[nextContactIndex] =
    Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
  initializedContacts = std::max(nextContactIndex + 1, initializedContacts);
  nextContactIndex = (nextContactIndex + 1) % maxContacts;
}

void
PhoneBook::search()
{
  if (initializedContacts < 0) {
    ioDevice.writeOutputLine("PhoneBook is empty");
    return;
  }
  displayAvailableContacts();

  const int indexSelected = std::atoi(ioDevice.readInputLine().data());
  if (initializedContacts >= 0 && indexSelected >= 0 &&
      indexSelected <= initializedContacts) {
    displayContactInfo(indexSelected);
  } else {
    ioDevice.writeOutputLine("Invalid Option");
  }
}

const Contact&
PhoneBook::getContact(int index)
{
  return contacts[index];
}

void
PhoneBook::displayContactInfo(int index)
{
  std::stringstream contactData;
  contactData << contacts[index];
  ioDevice.writeOutputLine(contactData.str());
}

int
PhoneBook::getNumInitializedContacts() const
{
  return initializedContacts;
}

void
PhoneBook::writeContactsTableHeader()
{
  const int colWidth = 10;
  const char separator = '|';
  std::stringstream header;

  header << separator << std::setw(colWidth) << "Index";
  header << separator << std::setw(colWidth) << "First Name";
  header << separator << std::setw(colWidth) << "Last Name";
  header << separator << std::setw(colWidth) << "Nickname" << separator;
  ioDevice.writeOutputLine(header.str());
}

void
PhoneBook::displayAvailableContacts()
{
  const int colWidth = 10;
  const char separator = '|';

  writeContactsTableHeader();
  for (int i = 0; i < initializedContacts; ++i) {
    std::stringstream line;
    line << separator << std::setw(colWidth) << i << separator;
    line << getContact(i).getFormatedPublicInfo();
    ioDevice.writeOutputLine(line.str());
  }
}
