#include "FileHandle.hpp"

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
