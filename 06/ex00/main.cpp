#include "ConversionPrinter.hpp"

int
main(int argc, const char* argv[])
{
  if (argc != 2)
    return 1;
  ConversionPrinter conversionPrinter(argv[1]);
  conversionPrinter.print();
}
