if (UNIT_TEST_BUILD)

    get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    message(STATUS "Creating [ ${COMPONENT_NAME} ] unit tests static library")

    add_library(${COMPONENT_NAME}
        platform.cpp
        platform_tests.cpp
    )
    
    target_include_directories(${COMPONENT_NAME} PUBLIC .)
    target_link_libraries(${COMPONENT_NAME} PUBLIC esp32_gpio_driver)
    target_link_libraries(${COMPONENT_NAME} PRIVATE CppUTest)

else()
    idf_component_register(SRCS "platform.cpp"
    INCLUDE_DIRS "."
    REQUIRES esp32_gpio_driver
    )
endif()
