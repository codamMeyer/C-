#include "Converter.hpp"
#include <iomanip>
#include <iostream>
int
main(int argc, const char* argv[])
{
  if (argc != 2)
    return 1;
  std::cout << std::fixed;
  std::cout << std::setprecision(1);
  Converter num(argv[1]);

  std::cout << "char: ";
  try {
    std::cout << static_cast<char>(num) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "int: ";
  try {
    std::cout << static_cast<int>(num) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "float: ";
  try {
    std::cout << static_cast<float>(num) << "f\n";
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "double: ";
  try {
    std::cout << static_cast<double>(num) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}