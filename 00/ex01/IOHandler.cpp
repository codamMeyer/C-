#include "IOHandler.hpp"
#include "IODevice.hpp"
#include "PhoneBook.hpp"

IOHandler::IOHandler(IODevice& ioDevice, PhoneBook& phoneBook)
  : ioDevice(ioDevice)
  , phoneBook(phoneBook)
{}

void
IOHandler::handleInput()
{
  while (true) {
    std::string input = ioDevice.readInputLine();
    if (input == EXIT_STR)
      return;
    else if (input == ADD_STR)
      phoneBook.add();
    else if (input == SEARCH_STR)
      phoneBook.search();
  }
}
