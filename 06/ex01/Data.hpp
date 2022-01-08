#ifndef DATA_H
#define DATA_H
#include <string>

struct Data
{
  Data(int id, const std::string& name);
  int id;
  std::string name;
};

#endif // DATA_H