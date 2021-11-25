#ifndef SED_H
#define SED_H
#include <fstream>
#include <iostream>

class SedString
{
public:
  static std::string run(const std::string& stringToSed,
			 const std::string& toReplace,
			 const std::string& replacement);
};

class FileHandle
{
public:
  FileHandle(const std::string& filename, std::ios_base::openmode mode);
  ~FileHandle();
  std::fstream& get();

private:
  std::fstream file;
};

class SedFile
{
public:
  SedFile();
  static void run(const std::string& filename,
		  const std::string& toReplace,
		  const std::string& replacement);
};

#endif // SED_H