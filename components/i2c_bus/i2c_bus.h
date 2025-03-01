#ifndef I2C_BUS_H
# define I2C_BUS_H

#include "driver/i2c.h"
#include "esp_err.h"

extern i2c_master_bus_handle_t i2c_bus;

esp_err_t i2c_bus_init(void);

#endif // I2C_BUS_H