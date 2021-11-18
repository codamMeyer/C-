#include <catch2/catch.hpp>
#include "megaphone.hpp"
#include <iostream>
#include <sstream>

TEST_CASE( "Feedback Noise" )
{
	std::ostringstream os;
	std::string expected = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";

	Megaphone megaphone(os);

	megaphone.feedback_noise();

	CHECK(expected == os.str());
}

TEST_CASE( "one input" )
{
	std::ostringstream os;
	std::string expected = "HELLO HELLO HELLO\n";
	char *input[] = {"           hello HELLO HeLlO         "};
	Megaphone megaphone(os);

	megaphone.increase_volume(1, input);
	CHECK(expected == os.str());
}
