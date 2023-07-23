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
# Helper Functions
# ############################################################################################################

include(FetchContent)

#[[
Shallow clone and add a CMake project from GitHub.

Options:
`ownerRepoTagString`
  A string in the form of owner/repo@tag (e.g., "thezhe/CppTemplate@v1.0.0").
]]
function(fetch_github ownerRepoTagString)
    string(REGEX REPLACE "[/@]" ";" owner_repo_tag_list ${ownerRepoTagString})
    list(POP_FRONT owner_repo_tag_list owner repo tag)

    FetchContent_Declare(
        ${repo}_${tag}
        GIT_REPOSITORY "https://github.com/${owner}/${repo}.git"
        GIT_TAG ${tag}
        GIT_SHALLOW ON
    )
    FetchContent_MakeAvailable(${repo}_${tag})
endfunction()

#[[
Add a header-only library.

Options:
`interfaceName`
The name of the library.

Note:
Also adds `${PROJECT_NAME}::${interfaceName}` as a valid library name.
]]
function(add_interface interfaceName)
    add_library(${interfaceName} INTERFACE)
    add_library(${PROJECT_NAME}::${interfaceName} ALIAS ${interfaceName})
endfunction()

#[[
Add a test executable for a library.

Options:
`testName`
The output variable. Set to the name of the test executable target.

`libraryName`
The name of the library target to link to `testName`.
#]]
function(add_library_test testName libraryName)
    string(REGEX REPLACE "::" "_" test_name ${libraryName})
    string(APPEND test_name "Test")

    add_executable(${test_name})
    add_test(${test_name} ${test_name})
    target_link_libraries(${test_name} PRIVATE ${libraryName})

    set(${testName}
        ${test_name}
        PARENT_SCOPE
    )
endfunction()

#[[
Install a target to ${CMAKE_INSTALL_PREFIX}.
]]
function(install_target_to_prefix targetName)
    install(TARGETS ${targetName} DESTINATION ${CMAKE_INSTALL_PREFIX})
endfunction()

# ############################################################################################################
# Deps
# ############################################################################################################

# fetch_github("thezhe/CppConfigs@v0.9.1") # Optional opinionated C++ config files

# ############################################################################################################
# Src
# ############################################################################################################

# CppTemplate::libCppTemplate
add_library(libCppTemplate STATIC)
add_library(CppTemplate::libCppTemplate ALIAS libCppTemplate)

target_include_directories(libCppTemplate PUBLIC include)
target_sources(libCppTemplate PRIVATE src/CppTemplate/CppTemplate.cpp)

# CppTemplate
add_executable(CppTemplate)
target_link_libraries(CppTemplate PRIVATE libCppTemplate)

target_sources(CppTemplate PRIVATE src/main.cpp)

# ############################################################################################################
# Test
# ############################################################################################################

enable_testing()

add_library_test(CppTemplateTest CppTemplate::libCppTemplate)
target_sources(${CppTemplateTest} PRIVATE test/CppTemplate/CppTemplateTest.cpp)

# ############################################################################################################
# Install
# ############################################################################################################

install_target_to_prefix(CppTemplate)
