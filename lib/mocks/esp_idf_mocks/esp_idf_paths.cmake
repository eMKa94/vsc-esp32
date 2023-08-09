# ESP-IDF components include paths have to be redeclared
# so the unit test build will know to reference them

# The "GLOBAL_ESP_IDF_PATH" should be set in the root CMakeLists.txt file

# This .cmake file should be included in the root CMakeLists.txt file 
# after the "GLOBAL_ESP_IDF_PATH" is set

set(ESP_IDF_INCLUDE_PATHS

${GLOBAL_ESP_IDF_PATH}/components/driver/gpio/include
${GLOBAL_ESP_IDF_PATH}/components/driver/gpio/include
${GLOBAL_ESP_IDF_PATH}/components/esp_common/include
${GLOBAL_ESP_IDF_PATH}/components/esp_hw_support/include
${GLOBAL_ESP_IDF_PATH}/components/soc/esp32/include
${GLOBAL_ESP_IDF_PATH}/components/soc/esp32c2/include
${GLOBAL_ESP_IDF_PATH}/components/hal/include
${GLOBAL_ESP_IDF_PATH}/components/esp_rom/include
${GLOBAL_ESP_IDF_PATH}/components/freertos/FreeRTOS-Kernel/include
${GLOBAL_ESP_IDF_PATH}/components/freertos/config/include/freertos
${GLOBAL_ESP_IDF_PATH}/components/freertos/config/include
${GLOBAL_ESP_IDF_PATH}/components/freertos/config/linux/include
${GLOBAL_ESP_IDF_PATH}/components/freertos/FreeRTOS-Kernel/portable/linux/include
${GLOBAL_ESP_IDF_PATH}/components/esp_system/include
${GLOBAL_ESP_IDF_PATH}/components/riscv/include



)
