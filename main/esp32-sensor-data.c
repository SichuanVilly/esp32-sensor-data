#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
        printf("setup...\n");
        while (true)
        {
                vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
}
