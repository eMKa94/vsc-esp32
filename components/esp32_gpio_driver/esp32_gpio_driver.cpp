#include "esp32_gpio_driver.h"

namespace Interface
{

Esp32GpioOutput::Esp32GpioOutput(gpio_num_t esp32GpioNumber) : mEsp32GpioNumber(esp32GpioNumber)
{
}

void Esp32GpioOutput::init()
{

    gpio_config_t config = {
        .pin_bit_mask = (1UL << (uint64_t)mEsp32GpioNumber),
        .mode         = GPIO_MODE_INPUT_OUTPUT,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type    = GPIO_INTR_DISABLE};

    gpio_config(&config);
}

void Esp32GpioOutput::setLevel(EGpioLevel newLevel)
{
    gpio_set_level(mEsp32GpioNumber, static_cast<uint32_t>(newLevel));
}

EGpioLevel Esp32GpioOutput::getLevel()
{

    return gpio_get_level(mEsp32GpioNumber) ? EGpioLevel::HIGH : EGpioLevel::LOW;
}

} // namespace Interface
