#include "Array.hpp"
#include <assert.h>
#include <iostream>
#include <string>
#include <stdlib.h>

template<typename T>
void printArray(const T& array, const std::string& name)
{
  std::cout << "\n" << name;
  for (int i = 0; i < array.size(); ++i)
  {
    std::cout << array[i] << " ";  
  }
  std::cout << "\n";
}

template<typename T>
void testOutOfRange(T& array)
{
  try {
    std::cout << "\ntry: array[-2]\n";
    std::cout << array[-2] << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "\ntry: array[array.size()]\n";
    std::cout << array[array.size()] << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

int
main()
{
  const int size = 5;
  Array<int> original(size);
  Array<int> copy(original);

  printArray(original, "original int array: ");
  printArray(copy, "copy int array: ");

  for (int i = 0; i < size; ++i) { // setting values of original array
    original[i] = i + 10;
  }

  printArray(original, "original int array: ");
  printArray(copy, "copy int array: ");

  testOutOfRange(original);

  Array<std::string> arrayStr(size);
  Array<std::string> copyStr(arrayStr);

  printArray(arrayStr, "original string array: ");
  printArray(copyStr, "copy string array: ");

  for (int i = 0; i < size; ++i) { // setting values of copy array
    copyStr[i] = "apples";
  }

  printArray(arrayStr, "original string array: ");
  printArray(copyStr, "copy string array: ");

  testOutOfRange(arrayStr);
}
