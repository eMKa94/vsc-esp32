#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

#include "example_component.h"

extern "C" void app_main(void)
{
    printf("Hello world!\n");

    ComponentClass componentClassInstance;
    componentClassInstance.print_from_component();

    for (;;)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}