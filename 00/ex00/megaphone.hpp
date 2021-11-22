#ifndef MEGAPHONE_H
#define MEGAPHONE_H
#include <iostream>

class Megaphone
{
public:
  Megaphone(std::ostream& output);
  void feedback_noise();
  void increase_volume(int numInputs, const char* input[]);

private:
  std::string ltrim(const std::string& str);
  std::string rtrim(const std::string& str);
  std::string trim(const std::string& str);
  std::string to_upper(std::string str);
  std::ostream& output;
};

#endif