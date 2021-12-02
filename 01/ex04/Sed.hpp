#ifndef SED_H
#define SED_H
#include <iostream>
#include "FileHandle.hpp"

class SedString
{
public:
  SedString(const std::string& stringToSed,
	    const std::string& toReplace,
	    const std::string& replacement);
  std::string run();

private:
  void replaceOccurence(std::string& newString, size_t& occurence);

  const std::string& stringToSed;
  const std::string& toReplace;
  const std::string& replacement;
};

class SedFile
{
public:
  SedFile(const std::string& inputFilename);
  void run(const std::string& toReplace, const std::string& replacement);

private:
  void readAndReplace(const std::string& toReplace,
		      const std::string& replacement);

  FileHandle infile;
  std::string inputFilename;
};

#endif // SED_H