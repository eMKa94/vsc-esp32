if (UNIT_TEST_BUILD)

    get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    message(STATUS "Creating [ ${COMPONENT_NAME} ] unit tests static library")

    add_library(example_component
        example_component.cpp
        example_component_tests.cpp
    )
    target_include_directories(${COMPONENT_NAME} PUBLIC .)


else()
    idf_component_register(SRCS "example_component.cpp"
    INCLUDE_DIRS ".")
endif()
