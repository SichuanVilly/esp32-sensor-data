#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "dht_sensor.h"
#include "lcd_i2c.h"

int var = 0;
static SemaphoreHandle_t mutex;


void task_read_temperature_and_humidity_dht22(void * parameter)
{
    while (1)
    {
        dht_sensor_read();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    printf("setting up...\n");
    mutex = xSemaphoreCreateMutex();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    if (mutex == NULL) {
        perror("Mutex creation failed!\n");
        return;
    }
    printf("mutex created succesfully\n");
    printf("setup done...\n");
    display_on_screen();
    xTaskCreatePinnedToCore(&task_read_temperature_and_humidity_dht22, "PRINT_TASK", 4096, NULL, 1, NULL, 0);
}