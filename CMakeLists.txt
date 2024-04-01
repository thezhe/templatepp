# Settings
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
# cmake-lint: disable=C0103
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
enable_testing()
# Project
project(templatepp)
# Definitions (see https://github.com/thezhe/ci.cmake)
string(APPEND ci_build_version_string "${CI_BUILD_VERSION}")
string(LENGTH "${ci_build_version_string}" ci_build_version_exists)
if(NOT "${ci_build_version_exists}")
    set(ci_build_version_string "Development")
endif()
add_compile_definitions(CI_BUILD_VERSION="${ci_build_version_string}")
# Build
add_library(templatepp INTERFACE)
target_include_directories(templatepp INTERFACE include)
add_library(thezhe::templatepp ALIAS templatepp)
# Test
add_executable(main-test main-test.cpp)
target_link_libraries(main-test thezhe::templatepp)
add_test(NAME main-test COMMAND main-test)
# Install
install(TARGETS main-test)
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}_${CMAKE_SYSTEM_NAME}")
include(CPack)
