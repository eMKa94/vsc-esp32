set(COMPONENT_NAME "led_controller")
set(COMPONENT_SOURCES
    "led_controller.cpp"
)

set(COMPONENT_INCLUDE_DIRECTORIES
    "include"
)

set(COMPONENT_TEST_SOURCES
    "led_controller_test.cpp"
)

if(BUILD_FOR_TESTING)

add_library(${COMPONENT_NAME} ${COMPONENT_SOURCES} ${COMPONENT_TEST_SOURCES})
target_include_directories(${COMPONENT_NAME} PRIVATE
    ${COMPONENT_INCLUDE_DIRECTORIES}    
    ${GLOB_TEST_FRAMEWORK_INCLUDE_DIR}
    ${GLOB_COMMON_INCLUDE_DIR}
)
target_include_directories(${COMPONENT_NAME} INTERFACE "include")

else()
idf_component_register(
    SRCS "bomb.c"
    INCLUDE_DIRS "include"
    REQUIRES mbedtls
)
endif()