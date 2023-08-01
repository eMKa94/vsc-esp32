#include "CppUTest/TestHarness.h"
#include "bomb.h"
// #include "MockPrinter.h"
// #include "CircularBuffer.h"

TEST_GROUP(FirstTestGroup){};

TEST(FirstTestGroup, FirstTest)
{
    FAIL("Fail me!");
}
