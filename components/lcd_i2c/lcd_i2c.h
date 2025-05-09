#ifndef LCD_I2C_H
# define LCD_I2C_H

#include "driver/i2c_master.h"
# include "common.h"

# define LCD_ADDR 0X27
# define SCL_SPEED_HZ 50000
# define LCD_MAX_CHAR_WRITE_COUNT 16

# define I2C_SDA_PIN 21
# define I2C_SCL_PIN 22

typedef struct
{
    i2c_master_bus_handle_t bus;
    i2c_master_dev_handle_t dev;
} lcd_t;

void lcd_init(void);
esp_err_t lcd_bus_init(void);
esp_err_t lcd_send_byte(uint8_t data, uint8_t mode);
void lcd_send_string(char *str);
void lcd_set_cursor(uint8_t col, uint8_t row);
void lcd_print_sensor_data(data_t * sensor_data);

#endif // LCD_I2C_H