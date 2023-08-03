#include "led_controller.h"

LedController::LedController(Interface::GpioOutput& gpioOutput) : mGpioOutput(gpioOutput)
{
}

void LedController::enable()
{
    mGpioOutput.setLevel(Interface::EGpioLevel::HIGH);
}

void LedController::disable()
{
    mGpioOutput.setLevel(Interface::EGpioLevel::LOW);
}