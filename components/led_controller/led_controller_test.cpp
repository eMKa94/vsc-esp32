#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "interface/gpio_cpp_if_mock.h"
#include "led_controller.h"
#include <stdio.h>

// clang-format off
TEST_GROUP(LedControllerTestGroup)
{

    Interface::EGpioLevelComparator gpioLevelComparator;

    void setup()
    {
        mock().installComparator("Interface::EGpioLevel", gpioLevelComparator);
    }

    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
        mock().removeAllComparatorsAndCopiers();
    }
};
// clang-format on


TEST(LedControllerTestGroup, dummyTest)
{
    CHECK(true);
}

TEST(LedControllerTestGroup, dummyTestWithMock)
{
    Interface::GpioOutputMock gpioOutputMock;

    // Interface::EGpioLevel EXPECTED_GPIO_LEVEL = Interface::EGpioLevel::HIGH;

    mock()
        .expectOneCall("setLevel")
        .withParameterOfType("Interface::EGpioLevel", "newLevel", (void*)Interface::EGpioLevel::HIGH);

    LedController ledController(gpioOutputMock);

    ledController.enable();
}