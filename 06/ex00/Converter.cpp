#include "Converter.hpp"
#include <iostream>
#include <iterator>
#include <math.h>
#include <sstream>

Converter::Converter()
  : str("default")
{}

Converter::Converter(const std::string string)
  : str(string)
{}

Converter::Converter(const Converter& other)
  : str(other.str)
{}

Converter::~Converter() {}

Converter&
Converter::operator=(const Converter&)
{
  return *this;
}

Converter::operator char()
{
  const int long long intRep = atoi(str.data());
  if (isSpecialCase()) {
    throw ImpossibleConversionExepction();
  } else if (intRep >= 0 && intRep <= 33 && intRep < 127) {
    throw NonDisplayableConversionExepction();
  } else if (intRep < 0 || intRep >= 127) {
    throw ImpossibleConversionExepction();
  }

  return static_cast<char>(intRep);
}

Converter::operator int()
{
  if (isSpecialCase()) {
    throw ImpossibleConversionExepction();
  }
  long long i;
  std::istringstream(str) >> i;
  if (i > 2147483647 || i < -2147483647 - 1) {
    throw ImpossibleConversionExepction();
  }
  return i;
}

Converter::operator float()
{
  if (isSpecialCase()) {
    return nanf("nanf");
  }
  long long int i;
  std::istringstream(str) >> i;
  if (i > 2147483647 || i < -2147483647 - 1) {
    throw ImpossibleConversionExepction();
  }
  return static_cast<float>(i);
}

Converter::operator double()
{
  if (isSpecialCase()) {
    return nan("nan");
  }
  long long int i;
  std::istringstream(str) >> i;
  if (i > 2147483647 || i < -2147483647 - 1) {
    throw ImpossibleConversionExepction();
  }
  return static_cast<double>(i);
}

const char*
Converter::ImpossibleConversionExepction::what() const throw()
{
  return ("impossible");
}

const char*
Converter::NonDisplayableConversionExepction ::what() const throw()
{
  return ("Non displayable");
};

bool
Converter::isSpecialCase()
{
  static const int size = 4;
  static const std::string special_doubles[size] = {
    "inf", "+inf", "-inf", "nan"
  };
  static const std::string special_floats[size] = {
    "inff", "+inff", "-inff", "nanf"
  };
  for (int i = 0; i < size; ++i) {
    if (str.compare(special_doubles[i]) == 0) {
      return true;
    } else if (str.compare(special_floats[i]) == 0) {
      return true;
    }
  }
  return false;
}