#ifndef CONVERTER_H
#define CONVERTER_H
#include <string>

class Converter
{
  enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
  };

  union Types {
    char c;
    int i;
    float f;
    double d;
  };

  struct ConversionTypes
  {
    Types types;
    Type activeType;
  };

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
  ConversionTypes conversionTypes;

  bool isNaN() const;
  bool isPosInf() const;
  bool isNegInf() const;
  bool isIntMinOrMax(long int i) const;
  bool isFloatMinOrMax(double i) const;

  void parse();
};

#endif // CONVERTER_H

