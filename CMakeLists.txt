# Boilerplate
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)
enable_testing()
# Build
project(templatepp)
add_library(templatepp INTERFACE)
target_include_directories(templatepp INTERFACE include)
add_library(thezhe::templatepp ALIAS templatepp)
# Test
add_executable(CTest CTest.cpp)
target_link_libraries(CTest thezhe::templatepp)
add_test(CTest CTest)
# Install
install(TARGETS CTest)
# CPack
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}_${CMAKE_SYSTEM_NAME}")
include(CPack)
