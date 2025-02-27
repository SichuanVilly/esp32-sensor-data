idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "."
                    REQUIRES dht)

set(EXTRA_COMPONENT_DIRS ${CMAKE_SOURCE_DIR}/components/dht)
