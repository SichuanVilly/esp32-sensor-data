#ifndef LCD_I2C_H
# define LCD_I2C_H

# include "hal/lcd_types.h"
# include "i2c_bus.h"
# include "esp_lcd_panel_io.h"
//# include "esp_lcd_panel_ops.h"
//# include "esp_lvgl_port.h"
//# include "lvgl.h"

# define LCD_ADDR 0X27
# define SCL_SPEED_HZ 100000
# define CONTROL_PHASE_BYTES 1
# define DC_BIT_OFFSET 6
# define LCD_CMD_BITS 8
# define LCD_PARAM_BITS 8

void display_on_screen(void);

static esp_lcd_panel_io_handle_t io_handle;

esp_err_t lcd_init(void);

#endif // LCD_I2C_H