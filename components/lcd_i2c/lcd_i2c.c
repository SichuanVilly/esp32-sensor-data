#include "lcd_i2c.h"
#include "common.h"

#define LOG_TAG "LCD_I2C"

esp_lcd_panel_io_handle_t io_handle = NULL;

void lcd_send_command(uint8_t cmd) {
    uint8_t buffer[4];

    // Send high nibble
    buffer[0] = (cmd & 0xF0) | 0x08;  // High nibble + RS=0 (command mode)
    buffer[1] = (cmd & 0xF0) | 0x00;  // High nibble (Enable off)

    // Send low nibble
    buffer[2] = ((cmd << 4) & 0xF0) | 0x08; // Low nibble + RS=0
    buffer[3] = ((cmd << 4) & 0xF0) | 0x00; // Low nibble (Enable off)

   esp_lcd_panel_io_tx_param(io_handle, 1, buffer, 4);
    vTaskDelay(pdMS_TO_TICKS(2));  // Small delay for command execution
}

void lcd_send_char(char c) {
    uint8_t buffer[4];

    // Send high nibble
    buffer[0] = (c & 0xF0) | 0x0D;  // High nibble + RS bit
    buffer[1] = (c & 0xF0) | 0x09;  // High nibble (Enable off)
    
    // Send low nibble
    buffer[2] = ((c << 4) & 0xF0) | 0x0D; // Low nibble + RS bit
    buffer[3] = ((c << 4) & 0xF0) | 0x09; // Low nibble (Enable off)

   esp_lcd_panel_io_tx_param(io_handle, 1, buffer, 4);
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t pos = col + (row == 1 ? 0x40 : 0x00);  // Row 1 starts at 0x40
    lcd_send_command(0x80 | pos);  // Set DDRAM address
}

void lcd_print(const char *str)
{
    
    while (*str) 
    {
        lcd_send_char(*str);
        str++;
    }
    ESP_LOGI(LOG_TAG, "this goes on led screen");
}

esp_err_t io_handle_init(void)
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


esp_err_t lcd_init(void)
{
    esp_err_t status;

    status = io_handle_init();
    if (status != ESP_OK)
        return status;
    
    vTaskDelay(pdMS_TO_TICKS(50));

    lcd_send_command(0x33);  // Force into 8-bit mode
    lcd_send_command(0x32);  // Switch to 4-bit mode
    lcd_send_command(0x28);  // 4-bit, 2-line
    lcd_send_command(0x0C);  // Display ON, Cursor OFF
    lcd_send_command(0x06);  // Cursor moves right
    lcd_send_command(0x01);   // clear display

    return ESP_OK;
}
