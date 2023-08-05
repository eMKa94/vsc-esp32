#ifndef ESP32_GPIO_DRIVER_H
#define ESP32_GPIO_DRIVER_H

#include "gpio_cpp_if.h"

#include "driver/gpio.h"

/*
steps from example gpio



*/

namespace Interface
{

class Esp32GpioOutput : public GpioOutput
{
public:
    Esp32GpioOutput() = delete;
    Esp32GpioOutput(gpio_num_t esp32GpioNumber);

    virtual void       setLevel(EGpioLevel newLevel) override;
    virtual EGpioLevel getLevel() override;

    void init();

private:
    gpio_num_t mEsp32GpioNumber = GPIO_NUM_NC;
};


} // namespace Interface

#endif /* ESP32_GPIO_DRIVER */
