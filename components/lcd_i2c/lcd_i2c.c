#include "lcd_i2c.h"
#include "common.h"

#define LOG_TAG "LCD_I2C"

lcd_t *s_lcd;


void lcd_set_cursor(uint8_t col, uint8_t row) {
    uint8_t cmd;

    if (row == 0) {
        cmd = 0x80 + col; // First row (0x80 is the base address)
    } else if (row == 1) {
        cmd = 0xC0 + col; // Second row (0xC0 is the base address)
    } else {
        // For other rows, you can add more logic if your display supports them
        return;  // Invalid row for this display (only two rows supported in this example)
    }

    lcd_send_byte(cmd, 0);
}

void lcd_send_string(char *str)
{
    while (*str) {
        lcd_send_byte(*str++, 1);
    }
}

esp_err_t lcd_send_byte(uint8_t data, uint8_t mode) 
{
    esp_err_t err;

    if (s_lcd == NULL || s_lcd->dev == NULL) {
        ESP_LOGE(LOG_TAG, "LCD device not initialized!");
        return ESP_FAIL;
    }

    uint8_t upper_nibble = (data & 0xF0) | mode | 0x08; // Enable backlight
    uint8_t lower_nibble = ((data << 4) & 0xF0) | mode | 0x08;

    uint8_t data_bytes[] = {
        upper_nibble | 0x04, // Enable high
        upper_nibble,        // Enable low
        lower_nibble | 0x04, // Enable high
        lower_nibble         // Enable low
    };

    err = i2c_master_transmit(s_lcd->dev, data_bytes, sizeof(data_bytes), -1);
    if (err != ESP_OK) {
        ESP_LOGE(LOG_TAG, "Failed to send data to LCD: %s\n", esp_err_to_name(err));
        return err;
    }
    return ESP_OK;
}

esp_err_t bus_init(void)
{
    esp_err_t status;
    s_lcd = (lcd_t *)calloc(1, sizeof(lcd_t));
    if (s_lcd == NULL)
    {
        ESP_LOGE(LOG_TAG, "calloc failed to allocate any memory.");
        return -1;
    }

    i2c_master_bus_config_t bus_cfg = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .i2c_port = I2C_NUM_0,
        .sda_io_num = I2C_SDA_PIN,
        .scl_io_num = I2C_SCL_PIN,
        .flags.enable_internal_pullup = true,
    };

    status = i2c_new_master_bus(&bus_cfg, &s_lcd->bus);
    if (status != ESP_OK)
    {
        ESP_LOGE(LOG_TAG, "lcd initialization failed to create i2c master bus.");
        return status;
    }

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = LCD_ADDR,
        .scl_speed_hz = SCL_SPEED_HZ,
    };

    status = i2c_master_bus_add_device(s_lcd->bus, &dev_cfg, &s_lcd->dev);
    if (status != ESP_OK)
    {
        ESP_LOGE(LOG_TAG, "lcd initialization failed to add device to i2c master bus.");
        return status;
    }
    return ESP_OK;
}

void lcd_init() {
    vTaskDelay(50 / portTICK_PERIOD_MS);
    lcd_send_byte(0x03, 0);  // Send 0x03 to LCD to initiate the interface in 8-bit modee (first pulse)
    vTaskDelay(5 / portTICK_PERIOD_MS);
    lcd_send_byte(0x03, 0);  // Send 0x03 again to continue the initialization (second pulse)
    vTaskDelay(1 / portTICK_PERIOD_MS);
    lcd_send_byte(0x03, 0);  // Send 0x03 for the third pulse to further initialize and confirm 8-bit mode
    lcd_send_byte(0x02, 0);  // Change to 4-bit mode

    lcd_send_byte(0x60, 0);  // Function Set: 4-bit, 2 lines, 5x8 dots
    lcd_send_byte(0x0C, 0);  // Display ON, Cursor OFF
    lcd_send_byte(0x06, 0);  // Entry Mode Set: Move cursor right
    lcd_send_byte(0x01, 0);  // Clear display
    vTaskDelay(2 / portTICK_PERIOD_MS);
}

