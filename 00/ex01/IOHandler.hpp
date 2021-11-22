#ifndef IOHandler_H
#define IOHandler_H

#include "IODevice.hpp"
#include "PhoneBook.hpp"

#define EXIT_STR "EXIT"
#define ADD_STR "ADD"
#define SEARCH_STR "SEARCH"

class IOHandler
{
public:
  IOHandler(IODevice& ioDevice, PhoneBook& phoneBook);
  void handleInput();

private:
  IODevice& ioDevice;
  PhoneBook& phoneBook;
};

#endif