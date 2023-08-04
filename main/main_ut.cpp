#include "example_component.h"
#include <stdio.h>

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/IEEE754ExceptionsPlugin.h"
#include "CppUTestExt/MockSupportPlugin.h"

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

IMPORT_TEST_GROUP(example_component_tests);
IMPORT_TEST_GROUP(esp32_gpio_driver_tests);