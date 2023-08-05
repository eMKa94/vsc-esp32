cmake_minimum_required(VERSION 3.16)

if (UNIT_TEST_BUILD)

    add_executable(${CMAKE_PROJECT_NAME} main_ut.cpp)

else()

    idf_component_register(SRCS "main_esp32.cpp"
    INCLUDE_DIRS "")

endif()
