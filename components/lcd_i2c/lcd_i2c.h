#ifndef LCD_I2C_H
# define LCD_I2C_H

#include "driver/i2c_master.h"
//# include "esp_lcd_panel_ops.h"
//# include "esp_lvgl_port.h"
//# include "lvgl.h"

# define LCD_ADDR 0X27
# define SCL_SPEED_HZ 100000
# define LCD_MAX_CHAR_WRITE_COUNT 32

//scan defines
#define I2C_MASTER_SDA_IO    21
#define I2C_MASTER_SCL_IO    22
#define I2C_MASTER_NUM       I2C_NUM_0
#define I2C_MASTER_FREQ_HZ   100000
// # define CONTROL_PHASE_BYTES 1
// # define DC_BIT_OFFSET 6
// # define LCD_CMD_BITS 8
// # define LCD_PARAM_BITS 8

# define I2C_SDA_PIN 21
# define I2C_SCL_PIN 22

typedef struct
{
    i2c_master_bus_handle_t bus;
    i2c_master_dev_handle_t dev;
} lcd_t;


void lcd_init(void);
esp_err_t bus_init(void);
esp_err_t lcd_send_byte(uint8_t data, uint8_t mode);
void lcd_send_string(char *str);
void lcd_set_cursor(uint8_t col, uint8_t row);

#endif // LCD_I2C_H