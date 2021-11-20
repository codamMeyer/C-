#include "IODevice.hpp"
#include <string>

MockIODevice::MockIODevice() : nextInputToRead(0), maxInputIndex(5){}

std::string
MockIODevice::readInputLine()
{
  std::string nextInput = inputs[nextInputToRead];
  nextInputToRead = (nextInputToRead + 1) % maxInputIndex;
  return nextInput;
};
void MockIODevice::writeOutputLine(){}

void MockIODevice::setNextInput(const std::string &input, int index) 
{
    inputs[index] = input;
};