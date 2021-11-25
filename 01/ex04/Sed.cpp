#include "Sed.hpp"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
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

FileHandle::FileHandle(const std::string& filename,
		       std::ios_base::openmode mode)
{
  file.open(filename.data(), mode);
}

FileHandle::~FileHandle()
{
  file.close();
}

std::fstream&
FileHandle::get()
{
  return file;
}

SedFile::SedFile() {}

void
SedFile::run(const std::string& filename,
	     const std::string& toReplace,
	     const std::string& replacement)
{
  FileHandle infile(filename.data(), std::fstream::in);

  if (!infile.get()) {
    std::cout << filename << " doesn't exist\n";
    return;
  }
  const std::string outFilename = filename + ".replace";
  FileHandle outfile(outFilename.data(), std::fstream::out | std::fstream::app);

  std::string line;
  while (getline(infile.get(), line)) {
    outfile.get() << SedString::run(line, toReplace, replacement) << std::endl;
  }
}
