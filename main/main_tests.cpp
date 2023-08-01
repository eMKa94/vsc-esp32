#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/IEEE754ExceptionsPlugin.h"
#include "CppUTestExt/MockSupportPlugin.h"

// class MyDummyComparator : public MockNamedValueComparator
// {
// public:
//     virtual bool isEqual(const void* object1, const void* object2) _override
//     {
//         return object1 == object2;
//     }

//     virtual SimpleString valueToString(const void* object) _override
//     {
//         return StringFrom(object);
//     }
// };

int main(int ac, char** av)
{
    // MyDummyComparator dummyComparator;
    // MockSupportPlugin mockPlugin;
    // IEEE754ExceptionsPlugin ieee754Plugin;

    // mockPlugin.installComparator("MyDummyType", dummyComparator);
    // TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    // TestRegistry::getCurrentRegistry()->installPlugin(&ieee754Plugin);
    return CommandLineTestRunner::RunAllTests(ac, av);
}

IMPORT_TEST_GROUP(FirstTestGroup);

// #include "AllTests.h"
// #include <stdio.h>

// #include "bomb.h"

// int main(void)
// {
//     printf("Hello Unit Tests!\n");
//     detonate();
//     return 0;
// }
