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
  operator char() const;
  operator int() const;
  operator float() const;
  operator double() const;

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

  bool isNaN() const;
  bool isPosInf() const;
  bool isNegInf() const;
  bool isIntMinOrMax(long long int i) const;
  bool isFloatMinOrMax(double i) const;
};

#endif // CONVERTER_H