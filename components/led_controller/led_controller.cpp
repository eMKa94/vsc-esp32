#include "led_controller.h"

LedController::LedController(Interface::GpioOutput& gpioOutput) : mGpioOutput(gpioOutput)
{
}