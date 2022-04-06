#include "Converter.hpp"
#include <cctype>
#include <cstddef>
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
  switch (conversionTypes.activeType) {
    case CHAR:{
      return conversionTypes.types.c;
    }
    case INT:{
      long int i;
      std::istringstream(str) >> i;
      if (isIntMinOrMax(i)) {
        throw ImpossibleConversionExepction();
      }
      if (isNonDisplayableChar(conversionTypes.types.i)) {
      throw NonDisplayableConversionExepction();
      }
      if (conversionTypes.types.i < 0 || conversionTypes.types.i >= 127) {
      throw ImpossibleConversionExepction();
      }
      return static_cast<char>(conversionTypes.types.i);
    }
    case FLOAT:{
      if (isNonDisplayableChar(conversionTypes.types.f)) {
      throw NonDisplayableConversionExepction();
      }
      if (conversionTypes.types.f < 0 || conversionTypes.types.f >= 127) {
      throw ImpossibleConversionExepction();
      }
      return static_cast<char>(conversionTypes.types.f);
    }
    case DOUBLE:{
      if (isNonDisplayableChar(conversionTypes.types.d)) {
      throw NonDisplayableConversionExepction();
      }
      if (conversionTypes.types.d < 0 || conversionTypes.types.d >= 127) {
      throw ImpossibleConversionExepction();
      }
      return static_cast<char>(conversionTypes.types.d);
    }
    case IMPOSSIBLE:{
      throw ImpossibleConversionExepction();  
    }
  }
  return static_cast<char>(str[0]);
}

Converter::operator int() const
{
  switch (conversionTypes.activeType) {
    case CHAR:{
      return static_cast<int>(conversionTypes.types.c);
    }
    case INT:{
      return conversionTypes.types.i;
    }
    case FLOAT:{
      long int i;
      std::istringstream(str) >> i;
      if (isIntMinOrMax(i)) {
        throw ImpossibleConversionExepction();
      }
      return static_cast<int>(conversionTypes.types.f);
    }
    case DOUBLE:{
      long int i;
      std::istringstream(str) >> i;
      if (isIntMinOrMax(i)) {
        throw ImpossibleConversionExepction();
      }
      return static_cast<int>(conversionTypes.types.d);
    }
    case IMPOSSIBLE:{
      throw ImpossibleConversionExepction();  
    }
  }
  return static_cast<int>(str[0]);
}

Converter::operator float() const
{
  switch (conversionTypes.activeType) {
    case CHAR:{
      return static_cast<float>(conversionTypes.types.c);
    }
    case INT:{
      long int i;
      std::istringstream(str) >> i;
      if (isIntMinOrMax(i)) {
        throw ImpossibleConversionExepction();
      }
      return static_cast<float>(conversionTypes.types.i);
    }
    case FLOAT:{
      return conversionTypes.types.f;
    }
    case DOUBLE:{
      double i;
      std::istringstream(str) >> i;
      if (isFloatMinOrMax(i)) {
        throw ImpossibleConversionExepction();
      }
      return static_cast<float>(conversionTypes.types.d);
    }
    case IMPOSSIBLE:{
      if (isNaN()) {
        return std::numeric_limits<float>::quiet_NaN();
      }
      if (isPosInf()) {
        return std::numeric_limits<float>::infinity();
      }
      if (isNegInf()) {
        return -std::numeric_limits<float>::infinity();
      }
      throw ImpossibleConversionExepction();  
    }
  }
  return static_cast<float>(str[0]);
}

Converter::operator double() const
{
  switch (conversionTypes.activeType) {
    case CHAR:{
      return static_cast<double>(conversionTypes.types.c);
    }
    case INT:{
      long int i;
      std::istringstream(str) >> i;
      if (isIntMinOrMax(i)) {
        throw ImpossibleConversionExepction();
      }
      return static_cast<double>(conversionTypes.types.i);
    }
    case FLOAT:{
      return conversionTypes.types.f;
    }
    case DOUBLE:{
      double i;
      std::istringstream(str) >> i;
      if (isFloatMinOrMax(i)) {
        throw ImpossibleConversionExepction();
      }
      return static_cast<double>(conversionTypes.types.d);
    }
    case IMPOSSIBLE:{
      if (isNaN()) {
        return std::numeric_limits<double>::quiet_NaN();
      }
      if (isPosInf()) {
        return std::numeric_limits<float>::infinity();
      }
      if (isNegInf()) {
        return -std::numeric_limits<float>::infinity();
      }
      throw ImpossibleConversionExepction();  
    }
  }
  return static_cast<double>(str[0]);
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

bool Converter::isChar()
{
  return str.length() == 1 && !std::isdigit(str[0]);
}

bool Converter::isInt()
{
  if (str.length() > 11)
  {
    return false;
  }
  for (std::size_t i = 0; i < str.length(); ++i)
  {
    if (i == 0 && (str[i] == '+' || str[i] == '-'))
    {
      ++i;
    }
    if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

bool Converter::isFloat()
{
  const size_t len = str.length();
  if (len < 2)
  {
    return false;
  }

  bool hasOneFloatPoint = false;
  bool endsWithOneF =  (str[len - 1] == 'f');
 
  for (std::size_t i = 0; i < len - 1; ++i)
  {
    if (i == 0 && (str[i] == '+' || str[i] == '-'))
    {
      ++i;
    }
    if (str[i] == '.')
    {
      if (hasOneFloatPoint)
      {
        hasOneFloatPoint = false;
        return false;
      }
      else {
        hasOneFloatPoint = true;
      }
    }
    else if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return endsWithOneF && hasOneFloatPoint;
}

bool Converter::isDouble()
{
  const size_t len = str.length();
  if (len < 2)
  {
    return false;
  }

  bool hasOneFloatPoint = false;
 
  for (std::size_t i = 0; i < len; ++i)
  {
    if (i == 0 && (str[i] == '+' || str[i] == '-'))
    {
      ++i;
    }
    if (str[i] == '.')
    {
      if (hasOneFloatPoint)
      {
        hasOneFloatPoint = false;
        return false;
      }
      else {
        hasOneFloatPoint = true;
      }
    }
    else if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return hasOneFloatPoint;
}


bool Converter::isNonDisplayableChar(int i) const
{
  return (i >= 0 && i <= 31 && i < 127);
}

void Converter::parse()
{
  if (isChar())
  {
    conversionTypes.activeType = CHAR;
    conversionTypes.types.c = str[0];
    return ;
  }
  
  if (isInt())
  {
    conversionTypes.activeType = INT;
    std::stringstream(str) >> conversionTypes.types.i;
    return ;
  }

  if (isFloat())
  {
    conversionTypes.activeType = FLOAT;
    std::stringstream(str) >> conversionTypes.types.f;
    return ;
  }
  if (isDouble())
  {
    conversionTypes.activeType = DOUBLE;
    std::stringstream(str) >> conversionTypes.types.d;
    return ;
  }
  conversionTypes.activeType = IMPOSSIBLE;

}
