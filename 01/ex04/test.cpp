#include "Sed.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <string>

class SedTest
{
public:
  SedTest()
    : inputs{ "This is the first line with no occurence",
	      "Second line has one string to replace apples",
	      "I like green because the sky is green",
	      "I love cats because cats bark" }
  {
  }
  const std::string inputs[4];
};

TEST_CASE_METHOD(SedTest, "No occurence in string")
{
  CHECK(SedString(inputs[0], "banana", "apple").run() ==
	inputs[0]);
}

TEST_CASE_METHOD(SedTest, "One occurence in string")
{
  CHECK(SedString(inputs[0], "first", "second").run() ==
	"This is the second line with no occurence");
}

TEST_CASE_METHOD(SedTest, "Occurence in the beginning of string")
{
  CHECK(SedString(inputs[0], "This", "That").run() ==
	"That is the first line with no occurence");
}

TEST_CASE_METHOD(SedTest, "Occurence in the end of string")
{
  CHECK(SedString(inputs[0], "occurence", "hello").run() ==
	"This is the first line with no hello");
}

TEST_CASE_METHOD(SedTest, "whole line")
{
  CHECK(SedString(inputs[0], "This is the first line with no occurence", ".").run() ==
	".");
}

TEST_CASE_METHOD(SedTest, "More occurences in string")
{
  CHECK(SedString(inputs[1], "on", "ON").run() ==
	"SecONd line has ONe string to replace apples");
  CHECK(SedString(inputs[2], "green", "blue").run() ==
	"I like blue because the sky is blue");
  CHECK(SedString(inputs[3], "cats", "dogs").run() ==
	"I love dogs because dogs bark");
}

TEST_CASE_METHOD(SedTest, "Replace in a loop")
{
  std::string expected[4] = {
    "This is the first line with nOOOO OOOOccurence",
    "SecOOOOnd line has OOOOne string tOOOO replace apples",
    "I like green because the sky is green",
    "I lOOOOve cats because cats bark"
  };

  for (int i = 0; i < 4; ++i)
  {
    CHECK(SedString(inputs[i], "o", "OOOO").run() == expected[i]);
  }
}