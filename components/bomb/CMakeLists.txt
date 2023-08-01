set(COMPONENT_NAME "bomb")
set(COMPONENT_SOURCES
    "bomb.c"
)

if(BUILD_FOR_TESTING)

add_library(${COMPONENT_NAME} bomb.c)
target_include_directories(${COMPONENT_NAME} INTERFACE "include")
target_include_directories(${COMPONENT_NAME} PRIVATE "include")

else()
idf_component_register(
    SRCS "bomb.c"
    INCLUDE_DIRS "include"
    REQUIRES mbedtls
)
endif()