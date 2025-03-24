# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)
set(EXTRA_COMPONENT_DIRS components/ra01s)
set(EXTRA_COMPONENT_DIRS components/st7789)
set(EXTRA_COMPONENT_DIRS components/lora)
set(EXTRA_COMPONENT_DIRS components/ft6x36)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
# "Trim" the build. Include the minimal set of components, main, and anything it depends on.
idf_build_set_property(MINIMAL_BUILD ON)
project(Chirpy)
spiffs_create_partition_image(storage fonts FLASH_IN_PROJECT)