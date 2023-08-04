#include "example_component.h"
#include <stdio.h>

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/IEEE754ExceptionsPlugin.h"
#include "CppUTestExt/MockSupportPlugin.h"

int main(int ac, char** av)
{
    printf("       __  __ _  __                                \n"
           "      |  \\/  | |/ /                                \n"
           "   ___| \\  / | ' / __ _                            \n"
           "  / _ \\ |\\/| |  < / _` |                           \n"
           " |  __/ |  | | . \\ (_| |                           \n"
           "  \\___|_|  |_|_|\\_\\__,_|               _ _         \n"
           "      | |    | |  | |                 (_) |        \n"
           "   ___| | ___| | _| |_ _ __ ___  _ __  _| | ____ _ \n"
           "  / _ \\ |/ _ \\ |/ / __| '__/ _ \\| '_ \\| | |/ / _` |\n"
           " |  __/ |  __/   <| |_| | | (_) | | | | |   < (_| |\n"
           "  \\___|_|\\___|_|\\_\\\\__|_|  \\___/|_| |_|_|_|\\_\\__,_|\n"
           "                                                   \n");
    ComponentClass componentClassInstance;

    componentClassInstance.print_from_component();
    return CommandLineTestRunner::RunAllTests(ac, av);
}

IMPORT_TEST_GROUP(example_component_tests);