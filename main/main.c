#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "dht.h"

int var = 0;
static SemaphoreHandle_t mutex;


void read_temperature_and_humidity_dht22(void * parameter)
{
    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void print_task(void * parameter)
{
    int * var = (int*)parameter;
    while (1)
    {
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE)
        {
            printf("simple task number of tasks run: %d\n",  *var);
            (*var)++;
            xSemaphoreGive(mutex);
        }
            vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void task_1(void * parameter)
{
    int * var = (int*)parameter;

    while (1)
    {
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE)
        {
            printf("task2 number of tasks run: %d\n",*var);
            (*var)++;
            xSemaphoreGive(mutex);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    printf("setting up...\n");
    mutex = xSemaphoreCreateMutex();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    if (mutex == NULL) {
        printf("Mutex creation failed!\n");
        return;
    }
    printf("mutex created succesfully\n");
    printf("setup done...\n");
    xTaskCreatePinnedToCore(&print_task, "PRINT_TASK", 4096, (void *)&var, 1, NULL, 0);
    xTaskCreatePinnedToCore(&task_1, "TASK_1", 4096, (void *)&var, 1, NULL, 1);
}