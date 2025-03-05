#include "i2c_bus.h"

#define LOG_TAG "I2C_BUS"

esp_err_t i2c_bus_init(void)
{
    esp_err_t status;

    i2c_master_bus_config_t bus_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .i2c_port = I2C_NUM_0,
        .sda_io_num = I2C_SDA_PIN,
        .scl_io_num = I2C_SCL_PIN,
        .flags.enable_internal_pullup = true,
    };
    status = (i2c_new_master_bus(&bus_config, &i2c_bus));
    if (status != ESP_OK)
    {
        ESP_LOGE(LOG_TAG, "I2C bus init failed: %s", esp_err_to_name(status));
        return status;
    }
    return ESP_OK;
}
