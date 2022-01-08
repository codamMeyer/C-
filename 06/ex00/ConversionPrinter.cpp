#include "ConversionPrinter.hpp"
#include <iomanip>
#include <iostream>

ConversionPrinter::ConversionPrinter() {}

ConversionPrinter::ConversionPrinter(const std::string& input)
  : converter(input)
{}

ConversionPrinter::ConversionPrinter(const ConversionPrinter& ConversionPrinter)
  : converter(ConversionPrinter.converter)
{}

ConversionPrinter::~ConversionPrinter() {}

ConversionPrinter&
ConversionPrinter::operator=(const ConversionPrinter& other)
{
  converter = other.converter;
  return *this;
}

void
ConversionPrinter::print() const
{
  std::cout << std::fixed;
  std::cout << std::setprecision(1);
  printChar();
  printInt();
  printFloat();
  printDouble();
}

void
ConversionPrinter::printChar() const
{
  std::cout << "char: ";
  try {
    std::cout << static_cast<char>(converter) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

void
ConversionPrinter::printInt() const
{
  std::cout << "int: ";
  try {
    std::cout << static_cast<int>(converter) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

void
ConversionPrinter::printFloat() const
{
  std::cout << "float: ";
  try {
    std::cout << static_cast<float>(converter) << "f\n";
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

void
ConversionPrinter::printDouble() const
{
  std::cout << "double: ";
  try {
    std::cout << static_cast<double>(converter) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}
