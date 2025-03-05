#include "lcd_i2c.h"
#include "common.h"

#define LOG_TAG "LCD_I2C"

void display_on_screen(void)
{
    ESP_LOGI(LOG_TAG, "this goes on led screen");
}

esp_err_t lcd_init(void)
{
    esp_err_t status;

    esp_lcd_panel_io_i2c_config_t io_config = {
        .dev_addr = LCD_ADDR,
        .scl_speed_hz = SCL_SPEED_HZ,
        .control_phase_bytes = CONTROL_PHASE_BYTES,
        .dc_bit_offset = DC_BIT_OFFSET,
        .lcd_cmd_bits = LCD_CMD_BITS,
        .lcd_param_bits = LCD_PARAM_BITS,
    };
    status = esp_lcd_new_panel_io_i2c(i2c_bus, &io_config, &io_handle);
    if (status != ESP_OK)
    {
        ESP_LOGE(LOG_TAG, "LCD init failed: %s", esp_err_to_name(status));
        return status;
    }
    return ESP_OK;
}
