#ifndef FILEHANDLE_H
# define FILEHANDLE_H
# include <fstream>

class FileHandle
{
public:
  FileHandle(const std::string& filename, std::ios_base::openmode mode);
  ~FileHandle();
  std::fstream& get();

private:
  std::fstream file;
};

#endif // FILEHANDLE_H