# ############################################################################################################
# Project
# ############################################################################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)
endif()

cmake_minimum_required(VERSION 3.15)

project(CppTemplate)

# ############################################################################################################
# CPM
# ############################################################################################################

set(CPM_DOWNLOAD_VERSION 0.38.2)

if(CPM_SOURCE_CACHE)
    set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
    set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else()
    set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif()

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
    file(DOWNLOAD
         https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
         ${CPM_DOWNLOAD_LOCATION}
    )
endif()

include(${CPM_DOWNLOAD_LOCATION})

# ############################################################################################################
# Helper Functions
# ############################################################################################################

#[[
Add a test executable for a library.

Options:
`libraryName`
The name of the library to test.
Creates an executable from the file in `test/${PROJECT_NAME}/${libraryName}.cpp`.
#]]
function(add_library_test libraryName)
    string(CONCAT test_name ${libraryName} "Test")

    add_executable(${test_name})
    target_link_libraries(${test_name} PRIVATE ${libraryName})
    target_sources(${test_name} PRIVATE test/${PROJECT_NAME}/${libraryName}.cpp)

    add_test(${test_name} ${test_name})
endfunction()

#[[
Install a target to ${CMAKE_INSTALL_PREFIX}.
]]
function(install_target targetName)
    install(TARGETS ${targetName} DESTINATION ${CMAKE_INSTALL_PREFIX})
endfunction()

# ############################################################################################################
# Deps
# ############################################################################################################

# cpmaddpackage("gh:fmtlib/fmt#7.1.3") cpmaddpackage("gh:thezhe/CppConfigs@0.9.1") # Optional opinionated C++
# config files

# ############################################################################################################
# Src
# ############################################################################################################

add_library(CppTemplate STATIC)
target_include_directories(CppTemplate PUBLIC include)
target_sources(CppTemplate PRIVATE src/CppTemplate/CppTemplate.cpp)

# ############################################################################################################
# Test
# ############################################################################################################

enable_testing()

add_library_test(CppTemplate)

# ############################################################################################################
# App
# ############################################################################################################

add_executable(App)
target_link_libraries(App PRIVATE ${PROJECT_NAME})
target_sources(App PRIVATE src/App.cpp)

# ############################################################################################################
# Install
# ############################################################################################################

install_target(TARGETS main)
