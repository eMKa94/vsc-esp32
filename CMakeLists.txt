cmake_minimum_required(VERSION 3.16)

option(UNIT_TEST_BUILD "Unit Tests build variant" OFF)

set(MASTER_CMAKE_PROJECT_NAME "" CACHE STRING "Master CMAKE project name")

if("${MASTER_CMAKE_PROJECT_NAME}" STREQUAL "")

set(MASTER_CMAKE_PROJECT_NAME "VSC_ESP32_TEMPLATE")

endif()

message(STATUS "MASTER_CMAKE_PROJECT_NAME = ${MASTER_CMAKE_PROJECT_NAME}")
if (UNIT_TEST_BUILD)

    include(utils.cmake)
    project(${MASTER_CMAKE_PROJECT_NAME}_ut)
    message(STATUS "Build :: Unit Tests")

    add_subdirectory(lib/cpputest)

    add_subdirectory(main)

    add_dependencies(${CMAKE_PROJECT_NAME}
        CppUTest
        CppUTestExt
    )

    set(GLOBAL_UT_FRAMEWORK_INTERFACE lib/cpputest/include/)
    SUBDIRLIST(COMPONENTS ${CMAKE_CURRENT_SOURCE_DIR}/components/)

    # Add each dir in components dir as a subdirectory
    foreach(COMPONENT ${COMPONENTS})
        add_subdirectory(components/${COMPONENT})
        
        target_link_libraries(${CMAKE_PROJECT_NAME} ${COMPONENT})
        add_dependencies(${CMAKE_PROJECT_NAME} ${COMPONENT})
        
        target_include_directories(${COMPONENT} PRIVATE ${GLOBAL_UT_FRAMEWORK_INTERFACE})
    
    endforeach()


else()

    message(STATUS "Build :: ESP32")
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(${MASTER_CMAKE_PROJECT_NAME})

endif()

