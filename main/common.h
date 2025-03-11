#ifndef COMMON_H
# define COMMON_H

# include "esp_log.h"
//# include "driver/gpio.h"
# include "freertos/FreeRTOS.h"
# include "freertos/task.h"
#include <string.h>

# include <stdio.h> // TODO: delete when printf is replaced

typedef struct
{
    float temp;
    float humid;
} data_t;

#endif