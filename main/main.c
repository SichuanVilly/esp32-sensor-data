#include "common.h"
#include "dht_sensor.h"
#include "lcd_i2c.h"

# define LOG_TAG "ESP32_SENSOR_DATA"

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
    ESP_LOGI(LOG_TAG, "setting up...");
    mutex = xSemaphoreCreateMutex();
    vTaskDelay(100 / portTICK_PERIOD_MS);
    if (mutex == NULL) {
        ESP_LOGE(LOG_TAG, "Mutex creation failed!");
        return;
    }
    ESP_LOGI(LOG_TAG, "setup done...");
    display_on_screen();
    xTaskCreatePinnedToCore(&task_read_temperature_and_humidity_dht22, "PRINT_TASK", 4096, NULL, 1, NULL, 0);
}