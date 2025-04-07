idf_component_register(SRCS "main.cpp"
        PRIV_REQUIRES spi_flash
        REQUIRES esp_driver_gpio driver spiffs esp_timer
        INCLUDE_DIRS "")