#include "Converter.hpp"
#include <cctype>
#include <iostream>
#include <iterator>
#include <limits>
#include <math.h>
#include <sstream>
#include <sys/stat.h>

Converter::Converter()
  : str("default")
{}

Converter::Converter(const std::string string)
  : str(string)
{
	parse();
}

Converter::Converter(const Converter& other)
  : str(other.str)
{}

Converter::~Converter() {}

Converter&
Converter::operator=(const Converter&)
{
  return *this;
}

Converter::operator char() const
{
	if (conversionTypes.activeType == CHAR)
	{
    return conversionTypes.types.c;
	}

  const int long intRep = atoi(str.data());

  if (isNaN() || isNegInf() || isPosInf()) {
    throw ImpossibleConversionExepction();
  } else if (intRep >= 0 && intRep <= 33 && intRep < 127) {
    throw NonDisplayableConversionExepction();
  } else if (intRep < 0 || intRep >= 127) {
    throw ImpossibleConversionExepction();
  }

  return static_cast<char>(intRep);
}

Converter::operator int() const
{
  if (isNaN()) {
    throw ImpossibleConversionExepction();
  }
  if (isPosInf() || isNegInf()) {
    throw ImpossibleConversionExepction();
  }

  long int i;
  std::istringstream(str) >> i;
  if (isIntMinOrMax(i)) {
    throw ImpossibleConversionExepction();
  }
  return static_cast<int>(i);
}

Converter::operator float() const
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

Converter::operator double() const
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
}

bool
Converter::isNaN() const
{
  if (str.compare("nan") == 0) {
    return true;
  } else if (str.compare("nanf") == 0) {
    return true;
  }
  return false;
}

bool
Converter::isPosInf() const
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
Converter::isNegInf() const
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
Converter::isIntMinOrMax(long int i) const
{
  return (i > std::numeric_limits<int>::max() ||
	  i < std::numeric_limits<int>::min());
}

bool
Converter::isFloatMinOrMax(double i) const
{
  const float lowest = -3.40282e+38;
  return (i > std::numeric_limits<float>::max() || i < lowest);
}

void Converter::parse()
{
  const bool isChar = str.length() == 1 && !std::isdigit(str[0]);
  if (isChar)
  {
    conversionTypes.activeType = CHAR;
    conversionTypes.types.c = str[0];
  }

//   switch (conversionTypes.activeType) {
//   case Type::CHAR:
//   	{
// 		std::cout << "is CHAR \n";
// 		break;
//     }
// 	case Type::INT:
//   	{
// 		std::cout << "is INT \n";
// 		break;
//     }
// 	case Type::FLOAT:
//   	{
// 		std::cout << "is FLOAT \n";
// 		break;
//     }
// 	case Type::DOUBLE:
//   	{
// 		std::cout << "is DOUBLE \n";
// 		break;
//     }
//   }

}
