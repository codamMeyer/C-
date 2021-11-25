#include "SedString.hpp"
#include <cstddef>
#include <iostream>
#include <string.h>

std::string
SedString::run(const std::string& stringToSed,
	       const std::string& toReplace,
	       const std::string& replacement)
{
  const size_t toReplaceLen = toReplace.length();
  const size_t toSedLen = stringToSed.length();
  size_t occurence = stringToSed.find(toReplace);
  size_t index = 0;

  std::string newString;

  newString += stringToSed.substr(index, occurence);
  while (occurence < toSedLen) {
    newString += replacement;
    index = occurence + toReplaceLen;
    occurence = stringToSed.find(toReplace, index);
    newString += stringToSed.substr(index, occurence - index);
  }
  return newString;
}
