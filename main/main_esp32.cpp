#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>


extern "C" void app_main(void)
{
    printf("Hello world!\n");

    for (;;)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}