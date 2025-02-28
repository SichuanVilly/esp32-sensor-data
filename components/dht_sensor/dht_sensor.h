#ifndef DHT_SENSOR_H
# define DHT_SENSOR_H
# include "dht.h"

#define DHT_PIN GPIO_NUM_4
#define DHT_TYPE DHT_TYPE_AM2301

void dht_sensor_read(void);

#endif  // DHT_SENSOR_H
