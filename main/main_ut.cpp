#include "example_component.h"
#include <stdio.h>

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/IEEE754ExceptionsPlugin.h"
#include "CppUTestExt/MockSupportPlugin.h"

int main(int ac, char** av)
{
    printf("Unit tests startup\n");

    ComponentClass componentClassInstance;

    componentClassInstance.print_from_component();
    return CommandLineTestRunner::RunAllTests(ac, av);
}

IMPORT_TEST_GROUP(example_component_tests);