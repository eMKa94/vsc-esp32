#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "esp32_gpio_driver.h"

// clang-format off
TEST_GROUP(esp32_gpio_driver_tests)
{
    void teardown()
    {
        mock().clear();
        mock().checkExpectations();
    }
}
;
// clang-format on

TEST(esp32_gpio_driver_tests, InitShouldCallGpio_config)
{

    Interface::Esp32GpioOutput ledGpio(GPIO_NUM_0);

    mock().expectOneCall("gpio_config");

    ledGpio.init();
    CHECK(true);
}

TEST(esp32_gpio_driver_tests, setLevelHighShouldProperlyCallIdfFunction)
{
    Interface::Esp32GpioOutput ledGpio(GPIO_NUM_0);

    mock().expectOneCall("gpio_set_level").withParameter("gpio_num", GPIO_NUM_0).withParameter("level", 1);

    ledGpio.setLevel(Interface::EGpioLevel::HIGH);
}