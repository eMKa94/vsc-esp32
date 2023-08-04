#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

#include "example_component.h"

extern "C" void app_main(void)
{
    printf("       __  __ _  __                                \n"
           "      |  \\/  | |/ /                                \n"
           "   ___| \\  / | ' / __ _                            \n"
           "  / _ \\ |\\/| |  < / _` |                           \n"
           " |  __/ |  | | . \\ (_| |                           \n"
           "  \\___|_|  |_|_|\\_\\__,_|               _ _         \n"
           "      | |    | |  | |                 (_) |        \n"
           "   ___| | ___| | _| |_ _ __ ___  _ __  _| | ____ _ \n"
           "  / _ \\ |/ _ \\ |/ / __| '__/ _ \\| '_ \\| | |/ / _` |\n"
           " |  __/ |  __/   <| |_| | | (_) | | | | |   < (_| |\n"
           "  \\___|_|\\___|_|\\_\\\\__|_|  \\___/|_| |_|_|_|\\_\\__,_|\n"
           "                                                   \n");

    printf("@: maciej.qb@gmail.com\n");

    for (;;)
    {

        printf("loop...\n");

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}