#include "contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

std::string Contact::truncate(std::string field)
{
	const int len = field.length();

	if (len > 10)
	{
		field.resize(9);
		field.resize(10, '.');
	}
	return field;
}

void Contact::display_data()
{
	const int colWidth = 10;
	const std::string separator = "|";

	std::cout << separator;
	std::cout << std::setw(colWidth) << truncate(first_name) << separator;
	std::cout << std::setw(colWidth) << truncate(last_name) << separator;
	std::cout << std::setw(colWidth) << truncate(nickname) << separator;
	std::cout << std::endl;
}

void Contact::display_lines()
{
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
}