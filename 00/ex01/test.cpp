#include <catch2/catch.hpp>
#include "yellow_book.hpp"
#include <iostream>
#include <sstream>

TEST_CASE( "Get Options" ) {

	std::stringstream ss;
	std::stringstream os;
	Yellow_book PhoneBook(os, ss);

	CHECK( PhoneBook.get_option("EXIT") == EXIT );
	CHECK( PhoneBook.get_option("ADD") == ADD );
	CHECK( PhoneBook.get_option("SEARCH") == SEARCH );
	CHECK( PhoneBook.get_option("blah") == INVALID );
}