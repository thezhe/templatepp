# Dependencies
include(FetchContent)
FetchContent_Declare(
    osv_scanner_lock
    GIT_REPOSITORY https://github.com/thezhe/osv_scanner_lock.git
    GIT_TAG fdffa355c21aa01c5d000f538c400ee0c8e63b80
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(osv_scanner_lock)
thezhe_osv_scanner_lock()
# Project
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
# cmake-lint: disable=C0103
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project("thezhe/templatepp")
# Build
add_library(templatepp INTERFACE)
target_include_directories(templatepp INTERFACE include)
add_library(thezhe::templatepp ALIAS templatepp)
# Top level only
if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()
# Test
enable_testing()
add_executable(test-templatepp test/templatepp.cpp)
target_link_libraries(test-templatepp PRIVATE thezhe::templatepp)
add_test(NAME test-templatepp COMMAND test-templatepp)
# Cross-compile example
thezhe_add_cross_compile_linux_mac_windows()
