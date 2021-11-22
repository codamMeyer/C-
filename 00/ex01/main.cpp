#include "IODevice.hpp"
#include "IOHandler.hpp"
#include "PhoneBook.hpp"

int
main(void)
{
  STDIODevice ioDevice;
  PhoneBook phoneBook(ioDevice);
  IOHandler ioHandler(ioDevice, phoneBook);

  ioHandler.handleInput();
  return 0;
}