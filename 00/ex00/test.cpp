#include "megaphone.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

class MegaphoneTest
{
public:
  MegaphoneTest()
	: megaphone(os)
  {}

  std::ostringstream os;
  Megaphone megaphone;
};

TEST_CASE_METHOD(MegaphoneTest, "Feedback Noise")
{
  const std::string expected = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";

  megaphone.feedback_noise();

  CHECK(expected == os.str());
}

TEST_CASE_METHOD(MegaphoneTest, "one input")
{
  const std::string expected = "HELLO HELLO HELLO\n";
  const char* input[] = { "executable ",
						  "           hello HELLO HeLlO         " };

  megaphone.increase_volume(2, input);

  CHECK(expected == os.str());
}

TEST_CASE_METHOD(MegaphoneTest, "two inputs")
{
  const std::string expected = "HELLO HELLO HELLO BLA\n";
  const char* input[] = { "executable ",
						  "           hello HELLO HeLlO         ",
						  "bla" };

  megaphone.increase_volume(3, input);

  CHECK(expected == os.str());
}
