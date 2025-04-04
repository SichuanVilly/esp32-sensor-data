#ifndef SD_CARD_H
# define SD_CARD_H

# define TAG "SD_CARD"
# define MOUNT_POINT "/sdcard"
# define PIN_NUM_MISO 19
# define PIN_NUM_MOSI 23
# define PIN_NUM_CLK 18
# define PIN_NUM_CS 5 

# include "common.h"
//# include "esp_vfs_fat.h"
# include "driver/sdspi_host.h"
//# include "sdmmc_cmd.h"
# include "esp_system.h"

typedef struct
{
    sdmmc_host_t host;
    sdmmc_card_t *card;
} sdcard_t;

void sdcard_init();
void write_data();

#endif // SD_CARD_H