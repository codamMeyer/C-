#include "contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

void Contact::display_data()
{
  const int colWidth = 10;
  const std::string separator = "|";

  std::cout << separator;
  std::cout << std::setw(colWidth) << first_name.substr(0, colWidth)
			<< separator;
  std::cout << std::setw(colWidth) << last_name.substr(0, colWidth) << separator;
  std::cout << std::setw(colWidth) << nickname.substr(0, colWidth) << separator;
  std::cout << std::endl;
}

void Contact::display_lines()
{
  std::cout << first_name << std::endl;
  std::cout << last_name << std::endl;
  std::cout << nickname << std::endl;
}