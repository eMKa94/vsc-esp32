cmake_minimum_required(VERSION 3.16)

option(UNIT_TEST_BUILD "Unit Tests build variant" OFF)

# APPLICATION must be the name of the directory nder app folder
set(APPLICATION "dmmy_app" CACHE STRING "Application to build") 

if("${APPLICATION}" STREQUAL "")

set(APPLICATION ${APPLICATION})

endif()

message(STATUS "APPLICATION = ${APPLICATION}")

set(GLOBAL_UT_FRAMEWORK_INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/cpputest/include/)
set(GLOBAL_COMMON_INTERFACES ${CMAKE_CURRENT_SOURCE_DIR}/lib/ecil/include)
set(GLOBAL_ESP_IDF_MOCKS_INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/mocks/esp_idf_mocks)
set(GLOBAL_ESP_IDF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/esp-idf)
set(GLOBAL_INTERFACES
    ${GLOBAL_COMMON_INTERFACES}
)

if (UNIT_TEST_BUILD)
    
    include(utils.cmake)
    include(lib/mocks/esp_idf_mocks/esp_idf_paths.cmake)
    project(${APPLICATION}_ut)
    message(STATUS "Build :: Unit Tests")

    add_subdirectory(lib/cpputest)
    add_subdirectory(lib/ecil)
    add_subdirectory(lib/mocks/esp_idf_mocks)
    add_subdirectory(main)

    add_subdirectory(app/${APPLICATION})
    
    SUBDIRLIST(COMPONENTS ${CMAKE_CURRENT_SOURCE_DIR}/components/)
    
    # Add each dir in components dir as a subdirectory
    foreach(COMPONENT ${COMPONENTS})
        add_subdirectory(components/${COMPONENT})
        
        target_link_libraries(${CMAKE_PROJECT_NAME} ${COMPONENT})
        add_dependencies(${CMAKE_PROJECT_NAME} ${COMPONENT})
        
        target_include_directories(${COMPONENT} PRIVATE ${GLOBAL_INTERFACES})
        
    endforeach()
        
    target_link_libraries(${CMAKE_PROJECT_NAME}
        ESP_IDF_MOCKS
        ecil_interface_mocks
        CppUTest
        CppUTestExt
        )
    
    add_dependencies(${CMAKE_PROJECT_NAME}
        ESP_IDF_MOCKS
        ecil_interface_mocks
        CppUTest
        CppUTestExt
    )

else()

    set(EXTRA_COMPONENT_DIRS app/${APPLICATION})
    message(STATUS "Build :: ESP32")
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(${APPLICATION})

endif()

