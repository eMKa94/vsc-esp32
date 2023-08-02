#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include "interface/gpio_cpp_if.h"

class LedController
{

public:
    LedController() = delete;
    LedController(Interface::GpioOutput& gpioOutput);

    void enable();
    void disable();

private:
    Interface::GpioOutput& mGpioOutput;
};

#endif /* LED_CONTROLLER_H */
