cmake_minimum_required(VERSION 3.16)

include(utils.cmake)

option(BUILD_FOR_TESTING "Build unit tests" OFF)
SUBDIRLIST(COMPONENTS ${CMAKE_CURRENT_SOURCE_DIR}/components/)

set(PROJECT_NAME VSC_ESP32_Template) 

if(${BUILD_FOR_TESTING})

    message(STATUS "Building for UNIT_TESTS")

    project(${PROJECT_NAME} C CXX)

    include(CTest)
    
    add_executable(${CMAKE_PROJECT_NAME} main/main_tests.cpp)
    
    
    set(GLOB_TEST_FRAMEWORK_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib/cpputest/include)
    set(GLOB_COMMON_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib/ecil)

    # Add each dir in components dir as a subdirectory
    foreach(COMPONENT ${COMPONENTS})
        add_subdirectory(components/${COMPONENT})
        target_link_libraries(${CMAKE_PROJECT_NAME} ${COMPONENT})
        add_dependencies(${CMAKE_PROJECT_NAME} ${COMPONENT})
    endforeach()

    add_subdirectory(lib/ecil)
    add_subdirectory(lib/cpputest)
    target_link_libraries(${CMAKE_PROJECT_NAME}
        CppUTest
        CppUTestExt
        ecil_interface_mocks
    )
    
    add_dependencies(${CMAKE_PROJECT_NAME}
        CppUTest
        CppUTestExt
        ecil_interface_mocks
    )
    
else()
    message(STATUS "Building for ESP32")
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(${PROJECT_NAME})
endif()
