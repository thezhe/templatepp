# Settings
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
# cmake-lint: disable=C0103
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)
enable_testing()
# Project
project(templatepp)
# Definitions (see https://github.com/thezhe/ci.cmake)
if(CI_BUILD_VERSION)
    add_compile_definitions(CI_BUILD_VERSION=${CI_BUILD_VERSION})
    message(STATUS "CI_BUILD_VERSION=${CI_BUILD_VERSION}")
else()
    add_compile_definitions(CI_BUILD_VERSION="Development")
    message(STATUS "CI_BUILD_VERSION=Development")
endif()
# Build
add_library(templatepp INTERFACE)
target_include_directories(templatepp INTERFACE include)
add_library(thezhe::templatepp ALIAS templatepp)
# Test
add_executable(test_main test.cpp)
target_link_libraries(test_main thezhe::templatepp)
add_test(NAME test_main COMMAND test_main)
# Install
install(TARGETS test_main)
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}_${CMAKE_SYSTEM_NAME}")
include(CPack)
