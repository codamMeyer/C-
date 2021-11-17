#include "yellow_book.hpp"
#include <iomanip>

void Yellow_book::display_list()
{
	const int colWidth = 10;
	const std::string separator = "|";

	if (!initialized)
	{ 
		return ;
	}
	out_stream << separator;
	out_stream << std::setw(colWidth) << "Option" << separator;
	out_stream << std::setw(colWidth) << "First Name" << separator;
	out_stream << std::setw(colWidth) << "Last Name" << separator;
	out_stream << std::setw(colWidth) << "Nickname" << separator;
	out_stream << std::endl;

	for (int i = 0; i < initialized; ++i) {
	  out_stream << separator << std::setw(colWidth) << i;
	  contacts[i].display_data();
	}
}

Options Yellow_book::get_option(std::string input)
{
	if (input.compare(options[EXIT]) == 0)
	  return EXIT;
	else if (input.compare(options[ADD]) == 0)
	  return ADD;
	else if (input.compare(options[SEARCH]) == 0)
	  return SEARCH;
	else
	  return INVALID;
}

void Yellow_book::add()
{
	out_stream << "First Name: ";
	getline(in_stream, contacts[next].first_name);

	out_stream << "Last Name: ";
	getline(in_stream, contacts[next].last_name);

	out_stream << "Nickame: ";
	getline(in_stream, contacts[next].nickname);

	out_stream << "Phone Number: ";
	getline(in_stream, contacts[next].phone_number);

	out_stream << "Darkest Secret: ";
	getline(in_stream, contacts[next].darkest_secret);

	next = (next + 1) % max;
	if (next > initialized)
		initialized = initialized + 1;
}
void Yellow_book::search()
{
	std::string option;
	int option_int;

	display_list();
	out_stream << "Please select your option: ";
	getline(in_stream, option);
	option_int = std::stoi(option);
	if (option_int >= 0 && option_int < initialized)
		contacts[option_int].display_lines();
	else
		out_stream << "invalid\n";
}