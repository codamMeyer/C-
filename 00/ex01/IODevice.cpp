#include "IODevice.hpp"
#include <iostream>
#include <string>

MockIODevice::MockIODevice() : nextInputToRead(0), maxInputIndex(5){}

std::string
MockIODevice::readInputLine()
{
  std::string nextInput = inputs[nextInputToRead];
  nextInputToRead = (nextInputToRead + 1) % maxInputIndex;
  return nextInput;
};
void MockIODevice::writeOutputLine(const std::string &str){
  os << str << std::endl;
}

void MockIODevice::setNextInput(const std::string &input, int index) 
{
    inputs[index] = input;
}

void MockIODevice::resetOutput() 
{
  os.str("");
  os.clear();
}

std::string MockIODevice::getOutput() const
{
  return os.str();
};

std::string
STDIODevice::readInputLine()
{
  std::string nextInput;
  std::getline(std::cin, nextInput);
  return nextInput;
};
void STDIODevice::writeOutputLine(const std::string &str){
  std::cout << str << std::endl;
}