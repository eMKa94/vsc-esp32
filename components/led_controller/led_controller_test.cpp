#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "interface/gpio_cpp_if_mock.h"
#include "led_controller.h"
#include <stdio.h>

// clang-format off
TEST_GROUP(LedControllerTestGroup)
{
    void teardown()
    {
        mock().clear();
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

    Interface::EGpioLevel EXPECTED_GPIO_LEVEL = Interface::EGpioLevel::HIGH;

    mock().expectOneCall("setLevel");
    mock().expectOneCall("getLevel").andReturnValue(&EXPECTED_GPIO_LEVEL);
    gpioOutputMock.setLevel(Interface::EGpioLevel::HIGH);
    Interface::EGpioLevel actualLevel = gpioOutputMock.getLevel();

    mock().checkExpectations();
    // CHECK_EQUAL(EXPECTED_GPIO_LEVEL, actualLevel);
}