set(COMPONENT_NAME "bomb")
set(COMPONENT_SOURCES
    "bomb.c"
)
set(COMPONENT_TEST_SOURCES
    "bomb_test.cpp"
)

if(BUILD_FOR_TESTING)


add_library(${COMPONENT_NAME} ${COMPONENT_SOURCES} ${COMPONENT_TEST_SOURCES})
target_include_directories(${COMPONENT_NAME} PRIVATE ${GLOB_TEST_FRAMEWORK_INCLUDE_DIR})
target_include_directories(${COMPONENT_NAME} INTERFACE "include")
target_include_directories(${COMPONENT_NAME} PRIVATE "include")

else()
idf_component_register(
    SRCS "bomb.c"
    INCLUDE_DIRS "include"
    REQUIRES mbedtls
)
endif()