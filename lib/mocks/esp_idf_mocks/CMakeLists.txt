cmake_minimum_required(VERSION 3.16)

add_library(ESP_IDF_MOCKS
    mock_src/gpio_mock.cpp    
)

target_include_directories(ESP_IDF_MOCKS PUBLIC
    "."
    ${GLOBAL_UT_FRAMEWORK_INTERFACE}
    ${ESP_IDF_INCLUDE_PATHS}
)
