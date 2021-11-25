#include "IODevice.hpp"
#include "SedString.hpp"
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
    createInput();
  }
  ~SedTest() { ioDevice.resetOutput(); }
  void createInput() { ioDevice.setInputArray(inputs, 4); }
  std::string inputs[10];
  MockIODevice ioDevice;
};

TEST_CASE_METHOD(SedTest, "No occurence in string")
{
  CHECK(SedString::run(ioDevice.readInputLine(), "banana", "apple") ==
	inputs[0]);
}

TEST_CASE_METHOD(SedTest, "One occurence in string")
{
  CHECK(SedString::run(ioDevice.readInputLine(), "first", "second") ==
	"This is the second line with no occurence");
}

TEST_CASE_METHOD(SedTest, "More occurences in string")
{
  ioDevice.readInputLine();
  CHECK(SedString::run(ioDevice.readInputLine(), "on", "ON") ==
	"SecONd line has ONe string to replace apples");
  CHECK(SedString::run(ioDevice.readInputLine(), "green", "blue") ==
	"I like blue because the sky is blue");
  CHECK(SedString::run(ioDevice.readInputLine(), "cats", "dogs") ==
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
    CHECK(SedString::run(ioDevice.readInputLine(), "o", "OOOO") == expected[i]);
}