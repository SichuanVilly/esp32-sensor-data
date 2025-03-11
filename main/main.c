#include "common.h"
#include "dht_sensor.h"
#include "lcd_i2c.h"

# define LOG_TAG "ESP32_SENSOR_DATA"

int var = 0;
static SemaphoreHandle_t sensor_data_mutex;

void task_display_data_in_lcd(void * parameter)
{
    data_t * sensor_data = (data_t *)parameter;
    while(1)
    {
        xSemaphoreTake(sensor_data_mutex, portMAX_DELAY);
        lcd_print_sensor_data(sensor_data);
        xSemaphoreGive(sensor_data_mutex);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void task_read_temperature_and_humidity_dht22(void * parameter)
{
    data_t * sensor_data = (data_t *)parameter;
    while (1)
    {
        xSemaphoreTake(sensor_data_mutex, portMAX_DELAY);
        dht_sensor_read(sensor_data);
        xSemaphoreGive(sensor_data_mutex);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    data_t sensor_data;

    ESP_LOGI(LOG_TAG, "setting up...");
    if (bus_init() == ESP_OK) 
    {
        lcd_init();
    } else {
        ESP_LOGE(LOG_TAG, "LCD initialization failed!");
        return;
    }
    ESP_LOGI(LOG_TAG, "AFTER INITIALIZATING BUS");
    sensor_data_mutex = xSemaphoreCreateMutex();
    if (sensor_data_mutex == NULL) {
        ESP_LOGE(LOG_TAG, "Mutex creation failed!");
        return;
    }
    ESP_LOGI(LOG_TAG, "setup done...");
    
    xTaskCreatePinnedToCore(&task_read_temperature_and_humidity_dht22, "READ_HUMID_TEMP_TASK", 4096, &sensor_data, 1, NULL, 0);
    xTaskCreatePinnedToCore(&task_display_data_in_lcd, "LCD_DISPLAY_TASK", 4096, &sensor_data, 1, NULL, 0);
}