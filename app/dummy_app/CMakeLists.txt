if (UNIT_TEST_BUILD)

    get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    message(STATUS "Creating [ ${COMPONENT_NAME} ] unit tests static library")

    add_library(${COMPONENT_NAME}
        dummy_app.cpp
        # dummy_app_test.cpp
    )
    target_include_directories(${COMPONENT_NAME} PUBLIC .)
    target_link_libraries(${COMPONENT_NAME} PUBLIC CppUTest platform)


else()
    idf_component_register(SRCS "dummy_app.cpp"
    INCLUDE_DIRS "."
    REQUIRES platform
    )
endif()
