#ifndef PLATFORM_H
#define PLATFORM_H

#include "esp32_gpio_driver.h"

void platformStart();

class Platform
{
public:
    Interface::Esp32GpioOutput debugLed;

    Platform();
    ~Platform() = default;

    void init();
};

#endif /* PLATFORM */
