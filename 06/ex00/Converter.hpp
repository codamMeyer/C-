#ifndef CONVERTER_H
#define CONVERTER_H
#include <string>

class Converter
{
public:
  Converter();
  Converter(const std::string string);
  Converter(const Converter& Converter);
  ~Converter();

  Converter& operator=(const Converter& other);
  operator char();
  operator int();
  operator float();
  operator double();

  class ImpossibleConversionExepction : public std::exception
  {
  public:
    virtual const char* what() const throw();
  };
  class NonDisplayableConversionExepction : public std::exception
  {
  public:
    virtual const char* what() const throw();
  };

private:
  const std::string str;

  bool isNaN();
  bool isPosInf();
  bool isNegInf();
  bool isIntMinOrMax(long long int i);
  bool isFloatMinOrMax(double i);
};

#endif // CONVERTER_H