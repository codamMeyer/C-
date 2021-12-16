#ifndef ODEVICE_H
#define ODEVICE_H

#include <sstream>
#include <string>

class ODevice
{
public:
  virtual void writeOutputLine(const std::string& str) = 0;
};

class MockODevice : public ODevice
{
public:
  MockODevice();
  void writeOutputLine(const std::string& str);
  void resetOutput();
  std::string getOutput() const;

private:
  std::ostringstream os;
};

class STDODevice : public ODevice
{
public:
  void writeOutputLine(const std::string& str);
};

#endif