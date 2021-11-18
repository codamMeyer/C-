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
	int next;
	int max;
	int initialized;
	Contact contacts[8];

	std::string options[3] = { "EXIT", "ADD", "SEARCH" };
	void display_list();
public:
	Yellow_book(std::ostream& out_stream, std::istream& in_stream)
	: out_stream(out_stream), in_stream(in_stream)  {
		next = 0;
		max = 8;
		initialized = 0;
	}
	Options get_option(std::string input);
	void add();
	void search();
	std::ostream& out_stream;
	std::istream& in_stream;
};

#endif