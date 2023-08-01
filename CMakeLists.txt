# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include(utils.cmake)

option(BUILD_FOR_TESTING "Build unit tests" OFF)
SUBDIRLIST(COMPONENTS ${CMAKE_CURRENT_SOURCE_DIR}/components/)

set(PROJECT_NAME VSC_ESP32_Template) 

if(${BUILD_FOR_TESTING})
    message(STATUS "Building for UNIT_TESTS")
    project(${PROJECT_NAME} C)
    add_subdirectory(main)
    foreach(COMPONENT ${COMPONENTS})
        add_subdirectory(components/${COMPONENT})
        target_link_libraries(${CMAKE_PROJECT_NAME} ${COMPONENT})
        add_dependencies(${CMAKE_PROJECT_NAME} ${COMPONENT})
    endforeach()
    
else()
    message(STATUS "Building for ESP32")
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(${PROJECT_NAME})
endif()
