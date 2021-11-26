#include "Karen.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <string>

class KarenTest
{
public:
  KarenTest()
    : karen(){};
  Karen karen;
};

TEST_CASE_METHOD(KarenTest, "invalid")
{
  CHECK(karen.getComplainLevelIndex("cry") == karen.INVALID);
}

TEST_CASE_METHOD(KarenTest, "debug")
{
  CHECK(karen.getComplainLevelIndex("DEBUG") == karen.DEBUG);
}

TEST_CASE_METHOD(KarenTest, "info")
{
  CHECK(karen.getComplainLevelIndex("INFO") == karen.INFO);
}

TEST_CASE_METHOD(KarenTest, "warning")
{
  CHECK(karen.getComplainLevelIndex("WARNING") == karen.WARNING);
}

TEST_CASE_METHOD(KarenTest, "error")
{
  CHECK(karen.getComplainLevelIndex("ERROR") == karen.ERROR);
}
