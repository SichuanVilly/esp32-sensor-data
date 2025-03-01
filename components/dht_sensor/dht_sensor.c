#include "dht_sensor.h"
#include "common.h"

#define LOG_TAG "DHT_SENSOR"

void dht_sensor_read(void)
{
    float temp = 0.f;
    float humid = 0.f;
    ESP_LOGI(LOG_TAG, "reading_temperature...");

    if (dht_read_float_data(DHT_TYPE, DHT_PIN, &humid, &temp) != ESP_OK)
    {
        ESP_LOGE(LOG_TAG, "Error reading humidity and temperature");
        return ;
    }
    printf("temp: %f C\nhumid: %f %%\n", temp, humid);
}
