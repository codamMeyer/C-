#ifndef YELLOW_BOOK_H
#define YELLOW_BOOK_H
#include <iostream>
#include "contact.hpp"

typedef enum Options
{
  EXIT = 0,
  ADD = 1,
  SEARCH = 2,
  INVALID = 3,
} Options;

class Yellow_book
{
private:
  int next = 0;
  int max = 8;
  int initialized = 0;
  Contact contacts[8];

  const std::string options[3] = { "EXIT", "ADD", "SEARCH" };
  void display_list();
public:
  Yellow_book(std::ostream& out_stream, std::istream& in_stream)
	: out_stream(out_stream), in_stream(in_stream)  {}
  Options get_option(std::string input);
  void add();
  void search();
  std::ostream& out_stream;
  std::istream& in_stream;
};


#endif