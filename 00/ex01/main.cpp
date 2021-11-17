#include "yellow_book.hpp"
#include "parser.hpp"

int main(void)
{
	Yellow_book phoneBook(std::cout, std::cin);
	Parser parser(std::cin);
	parser.parse(phoneBook);

  return 0;
}