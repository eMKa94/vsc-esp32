#!/bin/bash


echo "Project build start"

set -x # Debug mode
set -e # Exit immediately if any command fail

ROOT_BUILD_DIR=build_pack
UNIT_TESTS_BUILD_DIR=$ROOT_BUILD_DIR/build_unit_tests
PROD_BUILD_DIR=$ROOT_BUILD_DIR/build_prod

MASTER_CMAKE_PROJECT_NAME="AwesomeEsp32DevelopmentEnv"

build_unit_tests()
{
    cmake -B $UNIT_TESTS_BUILD_DIR -G Ninja . -DUNIT_TEST_BUILD="ON" -DMASTER_CMAKE_PROJECT_NAME:STRING="$MASTER_CMAKE_PROJECT_NAME"
    cmake --build $UNIT_TESTS_BUILD_DIR
}

build_production_code()
{
    source ./lib/esp-idf/export.sh
    cmake -B $PROD_BUILD_DIR -G Ninja . -DUNIT_TEST_BUILD="OFF" -DMASTER_CMAKE_PROJECT_NAME:STRING="$MASTER_CMAKE_PROJECT_NAME"
    cmake --build $PROD_BUILD_DIR

}

main()
{
    build_unit_tests
    ./$UNIT_TESTS_BUILD_DIR/main/$MASTER_CMAKE_PROJECT_NAME'_ut'
    build_production_code
}  

main