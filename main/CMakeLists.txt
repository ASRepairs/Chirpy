idf_component_register(SRCS "main.c"
        PRIV_REQUIRES spi_flash
        REQUIRES esp_driver_gpio driver spiffs
        INCLUDE_DIRS "")