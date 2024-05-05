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
project("thezhe/templatepp")
# Build
add_library(templatepp STATIC)
target_include_directories(templatepp PUBLIC include)
target_sources(templatepp PRIVATE src/Templatepp.cpp)
add_library(thezhe::templatepp ALIAS templatepp)
# Test and package
if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()
# Test
enable_testing()
add_executable(test-Templatepp test/Templatepp.cpp)
target_link_libraries(test-Templatepp thezhe::templatepp)
add_test(NAME test-Templatepp COMMAND test-Templatepp)
# Package
install(TARGETS test-Templatepp)
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}_${CMAKE_SYSTEM_NAME}")
include(CPack)
# ci
thezhe_add_ci()
