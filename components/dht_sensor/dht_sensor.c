#include "dht_sensor.h"
#include <stdio.h>

//static DHT dht(DHTPIN, DHTTYPE);

void dht_sensor_read(void)
{
    float temp = 0.f;
    float humid = 0.f;
    printf("reading_temperature...\n");

    if (dht_read_float_data(DHT_TYPE, DHT_PIN, &humid, &temp) != ESP_OK)
    {
        perror("Error reading humidity and temperature");
        return ;
    }
    printf("temp: %f C\nhumid: %f %%\n", temp, humid);
}