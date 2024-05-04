# Dependencies
include(FetchContent)
FetchContent_Declare(
    content_lock
    GIT_REPOSITORY https://github.com/thezhe/content_lock.git
    GIT_TAG 5ad74bf7e5360626d100e06eccfbcbbb06ab550d
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(content_lock)
thezhe_content_lock()
# Project
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
# cmake-lint: disable=C0103
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(templatepp)
# Build
add_library(templatepp INTERFACE)
target_include_directories(templatepp INTERFACE include)
add_library(thezhe::templatepp ALIAS templatepp)
# Test and package
if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()
# Test
enable_testing()
add_executable(test-templatepp test/templatepp.cpp)
target_link_libraries(test-templatepp thezhe::templatepp)
add_test(NAME test-templatepp COMMAND test-templatepp)
# Package
install(TARGETS test-templatepp)
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}_${CMAKE_SYSTEM_NAME}")
include(CPack)
# ci
thezhe_add_ci()
