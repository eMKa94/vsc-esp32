set(COMPONENT_SOURCES
    "main_esp32.c"
)


if(BUILD_FOR_TESTING)

add_executable(${CMAKE_PROJECT_NAME} main_tests.c)

else()
idf_component_register(SRCS ${COMPONENT_SOURCES}
INCLUDE_DIRS "")
endif()
