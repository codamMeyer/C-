#ifndef SEDSTRING_H
#define SEDSTRING_H
#include <iostream>

class SedString
{
public:
  static std::string run(const std::string& stringToSed,
			 const std::string& toReplace,
			 const std::string& replacement);
};

#endif // SEDSTRING_H