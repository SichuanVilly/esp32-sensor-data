# components/CMakeLists.txt

idf_component_register(
    SRCS 
        "dht_sensor/dht_sensor.c"  
    INCLUDE_DIRS 
        "dht_sensor"
    REQUIRES dht
)