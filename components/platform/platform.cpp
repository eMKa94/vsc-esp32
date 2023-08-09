#include "platform.h"
#include <stdio.h>

constexpr gpio_num_t DEBUG_LED_GPIO_NUMBER = GPIO_NUM_32;

extern void applicationStart(Platform& platform);

void platformStart()
{
    printf("Platform start!\n");

    Platform platform;

    platform.init();

    applicationStart(platform);
}

Platform::Platform() : debugLed(DEBUG_LED_GPIO_NUMBER)
{
}

void Platform::init()
{
    printf("Initializing Debug LED gpio\n");
    debugLed.init();
}
