#include "iter.hpp"
#include <assert.h>
#include <iostream>

void
printElement(const int& i)
{
  std::cout << i << " ";
}

void
incrementElement(int& i)
{
  ++i;
}

void
printElement(const std::string& i)
{
  std::cout << i << " ";
}

void
appendToElement(std::string& i)
{
  i += "_apple";
}

int
main(void)
{
  int array[4] = { 1, 2, 3, 4 };

  std::cout << "Original array:  ";
  ::iter(&array[0], 4, printElement);
  ::iter(&array[0], 4, incrementElement);
  std::cout << "\nAfter increment: ";
  ::iter(&array[0], 4, printElement);
  std::cout << "\n";

  std::string array2[4] = { "a", "b", "c", "d" };

  std::cout << "Original array:  ";
  ::iter(&array2[0], 4, printElement);
  ::iter(&array2[0], 4, appendToElement);
  std::cout << "\nAfter appending: ";
  ::iter(&array2[0], 4, printElement);
  std::cout << "\n";

  return 0;
}
