#include "Sed.hpp"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string.h>

SedString::SedString(const std::string& stringToSed,
		     const std::string& toReplace,
		     const std::string& replacement)
  : stringToSed(stringToSed)
  , toReplace(toReplace)
  , replacement(replacement)
{}

void
SedString::replaceOccurence(std::string& newString, size_t& occurence)
{
  const size_t index = occurence + toReplace.length();
  newString += replacement;
  occurence = stringToSed.find(toReplace, index);
  newString += stringToSed.substr(index, occurence - index);
}

std::string
SedString::run()
{
  size_t occurence = stringToSed.find(toReplace);

  std::string newString = stringToSed.substr(0, occurence);
  while (occurence < stringToSed.npos) {
    replaceOccurence(newString, occurence);
  }
  return newString;
}

SedFile::SedFile(const std::string& inputFilename)
  : infile(inputFilename.data(), std::fstream::in)
  , inputFilename(inputFilename)
{}

void
SedFile::run(const std::string& toReplace, const std::string& replacement)
{
  if (!infile.get()) {
    std::cout << inputFilename << " doesn't exist\n";
    return;
  }
  readAndReplace(toReplace, replacement);
}

void
SedFile::readAndReplace(const std::string& toReplace,
			const std::string& replacement)
{
  const std::string outFilename = inputFilename + ".replace";
  FileHandle outfile(outFilename.data(),
		     std::fstream::out | std::fstream::trunc |
		       std::fstream::app);
  std::string line;

  while (getline(infile.get(), line)) {
    outfile.get() << SedString(line, toReplace, replacement).run() << std::endl;
  }
}
