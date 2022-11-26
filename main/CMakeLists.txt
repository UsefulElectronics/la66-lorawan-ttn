file(GLOB_RECURSE IMAGE_SOURCES images/*.c)


idf_component_register(SRCS "main.c" "uart_config.c" "la66.c" "timer_config.c" "dth22.c" "temp_config.c" ${IMAGE_SOURCES}
                       INCLUDE_DIRS ".")
