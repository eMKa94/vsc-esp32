#include "CppUTestExt/MockSupport.h"
#include "driver/gpio.h"

esp_err_t gpio_config(const gpio_config_t* pGPIOConfig)
{
    mock().actualCall("gpio_config");
    return ESP_OK;
}

esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level)
{
    mock().actualCall("gpio_set_level").withParameter("gpio_num", gpio_num).withParameter("level", level);
    return ESP_OK;
}