#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include "yellow_book.hpp"

class Parser
{
public:
  Parser(std::istream& inputStream)
	: inputStream(inputStream)
  {}
  void parse(Yellow_book& phoneBook);

private:
  std::istream& inputStream;
};

#endif