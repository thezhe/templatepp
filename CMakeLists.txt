cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

project(library)
include_directories(include)
add_executable(CTest CTest.cpp)
add_test(CTest CTest)

# TODO add this an CPM to a different JUCE template repo

# if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT) message(STATUS "CMAKE_INSTALL_PREFIX defaulting to
# ${CMAKE_SOURCE_DIR}/install") set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install) endif()

# #[[ Install a target to ${CMAKE_INSTALL_PREFIX}. ]] function(install_target targetName) install(TARGETS
# ${targetName} DESTINATION ${CMAKE_INSTALL_PREFIX}) endfunction()
