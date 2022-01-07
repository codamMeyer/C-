#include "Converter.hpp"
#include <iostream>
#include <iterator>
#include <limits>
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
  if (isNaN() || isNegInf() || isPosInf()) {
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
  if (isNaN()) {
    throw ImpossibleConversionExepction();
  }
  if (isPosInf() || isNegInf()) {
    throw ImpossibleConversionExepction();
  }
  long long i;
  std::istringstream(str) >> i;
  if (isIntMinOrMax(i)) {
    throw ImpossibleConversionExepction();
  }
  return i;
}

Converter::operator float()
{
  if (isNaN()) {
    return std::numeric_limits<float>::quiet_NaN();
  }
  if (isPosInf()) {
    return std::numeric_limits<float>::infinity();
  }
  if (isNegInf()) {
    return -std::numeric_limits<float>::infinity();
  }

  double i;
  std::istringstream(str) >> i;
  if (isFloatMinOrMax(i)) {
    throw ImpossibleConversionExepction();
  }
  return static_cast<float>(i);
}

Converter::operator double()
{
  if (isNaN()) {
    return std::numeric_limits<double>::quiet_NaN();
  }
  if (isPosInf()) {
    return std::numeric_limits<float>::infinity();
  }
  if (isNegInf()) {
    return -std::numeric_limits<float>::infinity();
  }

  double i;
  std::istringstream(str) >> i;
  if (isFloatMinOrMax(i)) {
    throw ImpossibleConversionExepction();
  }
  return (i);
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
Converter::isNaN()
{
  if (str.compare("nan") == 0) {
    return true;
  } else if (str.compare("nanf") == 0) {
    return true;
  }
  return false;
}

bool
Converter::isPosInf()
{
  static const int size = 4;
  static const std::string special[size] = { "inf", "+inf", "inff", "+inff" };
  for (int i = 0; i < size; ++i) {
    if (str.compare(special[i]) == 0) {
      return true;
    }
  }
  return false;
}

bool
Converter::isNegInf()
{
  static const int size = 2;
  static const std::string special[size] = { "-inff", "-inf" };
  for (int i = 0; i < size; ++i) {
    if (str.compare(special[i]) == 0) {
      return true;
    }
  }
  return false;
}

bool
Converter::isIntMinOrMax(long long int i)
{
  return (i > std::numeric_limits<int>::max() ||
	  i < std::numeric_limits<int>::min());
}

bool
Converter::isFloatMinOrMax(double i)
{
  const float lowest = -3.40282e+38;
  return (i > std::numeric_limits<float>::max() || i < lowest);
}
