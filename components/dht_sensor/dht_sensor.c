#include "dht_sensor.h"
#include "common.h"

#define LOG_TAG "DHT_SENSOR"

void dht_sensor_read(data_t *sensor_data)
{
    ESP_LOGI(LOG_TAG, "reading_temperature...");
    if (dht_read_float_data(DHT_TYPE, DHT_PIN, &sensor_data->humid, &sensor_data->temp) != ESP_OK)
    {
        ESP_LOGE(LOG_TAG, "Error reading humidity and temperature");
        return ;
    }
    printf("temp: %f C\nhumid: %f %%\n", sensor_data->temp, sensor_data->humid);
}
