#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "esp32_gpio_driver.h"
#include "gpio_cpp_if_mock.h"

// clang-format off
TEST_GROUP(esp32_gpio_driver_tests)
{
    Interface::EGpioLevelComparator gpioLevelComparator;

    void setup()
    {
        mock().installComparator("Interface::EGpioLevel", gpioLevelComparator);
    }

    void teardown()
    {
        mock().clear();
        mock().checkExpectations();
        mock().removeAllComparatorsAndCopiers();
    }
}
;
// clang-format on

TEST(esp32_gpio_driver_tests, InitShouldCallGpio_config)
{

    Interface::Esp32GpioOutput ledGpio(GPIO_NUM_0);

    mock().expectOneCall("gpio_config").ignoreOtherParameters();

    ledGpio.init();
    CHECK(true);
}

TEST(esp32_gpio_driver_tests, setLevelHighShouldProperlyCallIdfFunction)
{
    Interface::Esp32GpioOutput ledGpio(GPIO_NUM_0);

    mock().expectOneCall("gpio_set_level").withParameter("gpio_num", GPIO_NUM_0).withParameter("level", 1);

    ledGpio.setLevel(Interface::EGpioLevel::HIGH);
}

TEST(esp32_gpio_driver_tests, setLevelLowShouldProperlyCallIdfFunction)
{
    Interface::Esp32GpioOutput ledGpio(GPIO_NUM_0);

    mock().expectOneCall("gpio_set_level").withParameter("gpio_num", GPIO_NUM_0).withParameter("level", 0);

    ledGpio.setLevel(Interface::EGpioLevel::LOW);
}

TEST(esp32_gpio_driver_tests, getLevelShouldReturnHigh)
{
    Interface::EGpioLevel      EXPECTED_LEVEL = Interface::EGpioLevel::HIGH;
    Interface::Esp32GpioOutput ledGpio(GPIO_NUM_0);

    mock().expectOneCall("gpio_get_level").withParameter("gpio_num", GPIO_NUM_0).andReturnValue(1);

    Interface::EGpioLevel actualLevel = ledGpio.getLevel();

    CHECK(EXPECTED_LEVEL == actualLevel);
}

TEST(esp32_gpio_driver_tests, getLevelShouldReturnLow)
{
    Interface::EGpioLevel      EXPECTED_LEVEL = Interface::EGpioLevel::LOW;
    Interface::Esp32GpioOutput ledGpio(GPIO_NUM_0);

    mock().expectOneCall("gpio_get_level").withParameter("gpio_num", GPIO_NUM_0).andReturnValue(0);

    Interface::EGpioLevel actualLevel = ledGpio.getLevel();

    CHECK(EXPECTED_LEVEL == actualLevel);
}