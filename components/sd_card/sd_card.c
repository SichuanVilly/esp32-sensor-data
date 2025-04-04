#include "sd_card.h"

sdcard_t sdcard;

void sdcard_init()
{
    // Configure SPI bus
    // sdcard.host = SDSPI_HOST_DEFAULT();
    // spi_bus_config_t bus_cfg = {
    //     .mosi_io_num = PIN_NUM_MOSI,
    //     .miso_io_num = PIN_NUM_MISO,
    //     .sclk_io_num = PIN_NUM_CLK,
    //     .quadwp_io_num = -1,
    //     .quadhd_io_num = -1,
    // };

    // ret = spi_bus_initialize(sdcard.host.slot, &bus_cfg, SDSPI_DEFAULT_DMA);
    // if (ret != ESP_OK) {
    //     ESP_LOGE(TAG, "Failed to initialize bus.");
    //     return;
    // }

    // // Configure SD card
    // sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    // slot_config.gpio_cs = PIN_NUM_CS;
    // slot_config.host_id = sdcard.host.slot;

    // // Mount the filesystem
    // esp_vfs_fat_sdmmc_mount_config_t mount_config = {
    //     .format_if_mount_failed = true,  // Format if mount fails
    //     .max_files = 5,
    //     .allocation_unit_size = 16 * 1024
    // };
}

void write_data()
{

    // ret = esp_vfs_fat_sdspi_mount(MOUNT_POINT, &sdcard.host, &slot_config, &mount_config, &sdcard.card);

    // if (ret != ESP_OK) {
    //     ESP_LOGE(TAG, "Failed to mount SD card.");
    //     return;
    // }

    // ESP_LOGI(TAG, "SD card mounted successfully.");

    // // Open a file and write to it
    // FILE *f = fopen(MOUNT_POINT "/test.txt", "w");
    // if (f == NULL) {
    //     ESP_LOGE(TAG, "Failed to open file for writing.");
    //     return;
    // }
    // fprintf(f, "Hello from ESP32!\n");
    // fclose(f);
    // ESP_LOGI(TAG, "File written successfully.");

    // // Read the file
    // f = fopen(MOUNT_POINT "/test.txt", "r");
    // if (f == NULL) {
    //     ESP_LOGE(TAG, "Failed to open file for reading.");
    //     return;
    // }

    // char line[64];
    // fgets(line, sizeof(line), f);
    // fclose(f);
    // ESP_LOGI(TAG, "File content: %s", line);

    // // Unmount and clean up
    // esp_vfs_fat_sdcard_unmount(MOUNT_POINT, sdcard.card);
    // ESP_LOGI(TAG, "SD card unmounted.");
}