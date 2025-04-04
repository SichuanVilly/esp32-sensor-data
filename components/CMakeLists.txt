# components/CMakeLists.txt

idf_component_register(
    SRCS 
        "dht_sensor/dht_sensor.c" 
        "lcd_i2c/lcd_i2c.c"
        "sd_card/sd_card.c"
    INCLUDE_DIRS 
        "dht_sensor"
        "lcd_i2c"
        "sd_card"
        ${CMAKE_SOURCE_DIR}/main #This is needed to include common.h
    REQUIRES dht
    REQUIRES driver
    REQUIRES esp_lcd)
