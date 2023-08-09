#include "CppUTest/TestHarness.h"

#include "platform.h"

#define TEST_SUITE_NAME platform_tests
TEST_GROUP(platform_tests){};

TEST(platform_tests, dummyTest)
{
    CHECK(true);
}