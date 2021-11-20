#ifndef IODEVICE_H
#define IODEVICE_H

#include <string>

class IODevice
{
public:
  virtual std::string readInputLine() = 0;
  virtual void writeOutputLine() = 0;
};

class MockIODevice : public IODevice
{
public:
  MockIODevice();
  std::string readInputLine();
  void writeOutputLine();

  void setNextInput(const std::string &input, int index);
private:
  std::string inputs[5];
  int nextInputToRead;
  const int maxInputIndex;
};

#endif