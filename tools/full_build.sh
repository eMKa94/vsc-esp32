#!/bin/bash


echo "Project build start"

# set -x # Debug mode
set -e # Exit immediately if any command fail

ROOT_BUILD_DIR=build_pack
UNIT_TESTS_BUILD_DIR=$ROOT_BUILD_DIR/build_unit_tests
PROD_BUILD_DIR=$ROOT_BUILD_DIR/build_prod

APPLICATION="dummy_app"

build_unit_tests()
{
    cmake -B $UNIT_TESTS_BUILD_DIR -G Ninja . -DUNIT_TEST_BUILD="ON" -DAPPLICATION:STRING="$APPLICATION"
    cmake --build $UNIT_TESTS_BUILD_DIR
}

build_production_code()
{
    source ./lib/esp-idf/export.sh
    cmake -B $PROD_BUILD_DIR -G Ninja . -DUNIT_TEST_BUILD="OFF" -DAPPLICATION:STRING="$APPLICATION"
    cmake --build $PROD_BUILD_DIR

}

main()
{
    echo "Building unit tests"
    build_unit_tests
    echo "Running unit tests"
    ./$UNIT_TESTS_BUILD_DIR/main/$APPLICATION'_ut' -v
    echo "Building production app"
    build_production_code
}  

main