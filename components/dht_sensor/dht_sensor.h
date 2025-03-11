#ifndef DHT_SENSOR_H
# define DHT_SENSOR_H
# include "dht.h"
# include "common.h"

# define DHT_PIN GPIO_NUM_4
# define DHT_TYPE DHT_TYPE_AM2301

void dht_sensor_read(data_t * sensor_data);

#endif  // DHT_SENSOR_H
