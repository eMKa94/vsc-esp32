cmake_minimum_required(VERSION 3.16)

option(UNIT_TEST_BUILD "Unit Tests build variant" OFF)

set(MASTER_CMAKE_PROJECT_NAME "" CACHE STRING "Master CMAKE project name")

if("${MASTER_CMAKE_PROJECT_NAME}" STREQUAL "")

set(MASTER_CMAKE_PROJECT_NAME "VSC_ESP32_TEMPLATE")

endif()

message(STATUS "MASTER_CMAKE_PROJECT_NAME = ${MASTER_CMAKE_PROJECT_NAME}")


set(GLOBAL_UT_FRAMEWORK_INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/cpputest/include/)
set(GLOBAL_COMMON_INTERFACES ${CMAKE_CURRENT_SOURCE_DIR}/lib/ecil/include)
set(GLOBAL_ESP_IDF_MOCKS_INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/mocks/esp_idf_mocks)
set(GLOBAL_ESP_IDF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/esp-idf)
set(GLOBAL_INTERFACES
    ${GLOBAL_UT_FRAMEWORK_INTERFACE}
    ${GLOBAL_COMMON_INTERFACES}
)

if (UNIT_TEST_BUILD)

    include(utils.cmake)
    include(lib/mocks/esp_idf_mocks/esp_idf_paths.cmake)
    project(${MASTER_CMAKE_PROJECT_NAME}_ut)
    message(STATUS "Build :: Unit Tests")

    add_subdirectory(lib/cpputest)
    add_subdirectory(lib/ecil)
    add_subdirectory(lib/mocks/esp_idf_mocks)
    add_subdirectory(main)

    
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

    message(STATUS "Build :: ESP32")
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(${MASTER_CMAKE_PROJECT_NAME})

endif()

