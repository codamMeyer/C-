#ifndef CONVERSIONPRINTER_H
#define CONVERSIONPRINTER_H
#include "Converter.hpp"
#include <string>

class ConversionPrinter
{
public:
  ConversionPrinter();
  ConversionPrinter(const std::string& input);
  ConversionPrinter(const ConversionPrinter& ConversionPrinter);
  ~ConversionPrinter();

  ConversionPrinter& operator=(const ConversionPrinter& other);
  void print() const;

private:
  void printChar() const;
  void printInt() const;
  void printFloat() const;
  void printDouble() const;
  
  Converter converter;
};

#endif // CONVERSIONPRINTER_H