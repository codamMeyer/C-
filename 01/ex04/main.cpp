#include "Sed.hpp"
#include <iostream>

int
main(int argc, const char* argv[])
{
  if (argc != 4) {
    std::cout
      << "usage: ./sedIsForLosers <filename> <stringToReplace> <replacement>\n";
    return 1;
  }
  SedFile(argv[1]).run(argv[2], argv[3]);
  return 0;
}