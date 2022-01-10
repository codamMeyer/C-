#include "Array.hpp"
#include <assert.h>
#include <iostream>
#include <string>

int
main()
{
  const int size = 5;
  Array<int> array(size);
  Array<int> copy(array);
  assert(array.size() == size);
  assert(copy.size() == size);
  std::cout << "Array content: ";
  for (int i = 0; i < size; ++i) {
    array[i] = i;
    std::cout << array[i] << " ";
  }
  std::cout << "\nCopy content: ";

  // checking if copy array isn't modified
  for (int i = 0; i < size; ++i) {
    assert(copy[i] == 0);
    std::cout << copy[i] << " ";
  }
  std::cout << "\n";

  Array<std::string> arrayStr(size);
  Array<std::string> copyStr(arrayStr);
  assert(arrayStr.size() == size);
  assert(copyStr.size() == size);
  std::cout << "ArrayStr content: ";
  for (int i = 0; i < size; ++i) {
    arrayStr[i] = "apple";
    std::cout << arrayStr[i] << " ";
  }
  std::cout << "\nCopyStr content: ";

  // checking if copyStr array isn't modified
  for (int i = 0; i < size; ++i) {
    assert(copyStr[i] == "\0");
    std::cout << copyStr[i] << " ";
  }
  std::cout << "\n";
}
