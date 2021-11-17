#include "parser.hpp"


void Parser::parse(Yellow_book& phoneBook)
{
	std::string input;
	while (true) {
	  getline(inputStream, input);
	  switch (phoneBook.get_option(input)) {
		case EXIT:
		  return;
		case ADD: {
		  phoneBook.add();
		  continue;
		}
		case SEARCH: {
		  phoneBook.search();
		  continue;
		}
		default:
		  continue;
	  }
	}
}
