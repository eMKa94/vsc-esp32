#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}


IMPORT_TEST_GROUP(BombTestGroup);
IMPORT_TEST_GROUP(LedControllerTestGroup);
