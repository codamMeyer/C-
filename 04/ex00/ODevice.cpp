#include "ODevice.hpp"
#include <iostream>
#include <string>

MockODevice::MockODevice() {}

void
MockODevice::writeOutputLine(const std::string& str)
{
  os << str;
}

void
MockODevice::resetOutput()
{
  os.str("");
  os.clear();
}

std::string
MockODevice::getOutput() const
{
  return os.str();
};

void
STDODevice::writeOutputLine(const std::string& str)
{
  std::cout << str << std::endl;
}