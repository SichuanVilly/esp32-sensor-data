#include "common.h"
#include "dht_sensor.h"
#include "lcd_i2c.h"

# define LOG_TAG "ESP32_SENSOR_DATA"

int var = 0;
static SemaphoreHandle_t mutex;

void task_display_data_in_lcd(void * parameter)
{
   // lcd_init();
    while(1)
    {
       // lcd_set_cursor(0, 0);  // Set cursor to first row, first column
       // lcd_print("Hello, World!");  // Print text
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

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
    // i2c_scan();
    // return ;
    ESP_LOGI(LOG_TAG, "setting up...");
    if (bus_init() == ESP_OK) 
    {
        lcd_init();
    } else {
        ESP_LOGE(LOG_TAG, "LCD initialization failed!");
    }
    lcd_send_string("Hello ESP32!");
   // return;
   // lcd_print("hello, alan");
    return;
    
    ESP_LOGI(LOG_TAG, "AFTER INITIALIZATING BUS");
    mutex = xSemaphoreCreateMutex();
    //vTaskDelay(100 / portTICK_PERIOD_MS);
    if (mutex == NULL) {
        ESP_LOGE(LOG_TAG, "Mutex creation failed!");
        return;
    }
    ESP_LOGI(LOG_TAG, "setup done...");
    
   // exit(1);
    //return ;
    xTaskCreatePinnedToCore(&task_read_temperature_and_humidity_dht22, "PRINT_TASK", 4096, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(&task_display_data_in_lcd, "LCD_TASK", 4096, NULL, 1, NULL, 0);
}