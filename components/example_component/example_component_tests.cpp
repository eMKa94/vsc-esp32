#include "CppUTest/TestHarness.h"

#include "example_component.h"

#define TEST_SUITE_NAME example_component_tests
TEST_GROUP(example_component_tests){};

TEST(example_component_tests, dummyTest)
{
    CHECK(true);
}