# components/CMakeLists.txt

idf_component_register(
    SRCS 
        "dht_sensor/dht_sensor.c" 
        "lcd_i2c/lcd_i2c.c"
    INCLUDE_DIRS 
        "dht_sensor"
        "lcd_i2c"
    REQUIRES dht
)