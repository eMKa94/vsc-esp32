if (UNIT_TEST_BUILD)

    get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    message(STATUS "Creating [ ${COMPONENT_NAME} ] unit tests static library")

    add_library(${COMPONENT_NAME}
    esp32_gpio_driver.cpp
    esp32_gpio_driver_tests.cpp
    )
    target_include_directories(${COMPONENT_NAME} PUBLIC include)


else()
    idf_component_register(SRCS "esp32_gpio_driver.cpp"
    INCLUDE_DIRS "include")
endif()
