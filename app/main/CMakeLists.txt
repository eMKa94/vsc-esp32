set(COMPONENT_SOURCES
    "main_esp32.cpp"
)

if(BUILD_FOR_TESTING)

else()
    idf_component_register(SRCS "main_esp32.cpp"
    INCLUDE_DIRS "")
endif()
