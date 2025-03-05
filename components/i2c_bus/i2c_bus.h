#ifndef I2C_BUS_H
# define I2C_BUS_H

# include "driver/i2c_master.h"
# include "driver/i2c_types.h"
# include "common.h"

# include "esp_err.h"

# define I2C_SDA_PIN 21
# define I2C_SCL_PIN 22


extern i2c_master_bus_handle_t i2c_bus;

esp_err_t i2c_bus_init(void);

#endif // I2C_BUS_H