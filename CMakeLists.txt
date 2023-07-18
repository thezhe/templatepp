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
``OWNER_REPO_TAG_STRING``
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
``INTERFACE_NAME``
The name of the library.

Note:
Also adds "${PROJECT_NAME}::${INTERFACE_NAME}" as a valid library name.
]]
function(add_interface interfaceName)
    add_library(${interfaceName} INTERFACE)
    add_library(${PROJECT_NAME}::${interfaceName} ALIAS ${interfaceName})
endfunction()

#[[
Install a file to ${CMAKE_INSTALL_PREFIX}.

Options:
``FILE_PATH``
File path relative to ${CMAKE_SOURCE_DIR}.
]]
function(install_file_to_prefix filePath)
    install(FILES ${filePath} DESTINATION ${CMAKE_INSTALL_PREFIX})
endfunction()

#[[
Install a target to ${CMAKE_INSTALL_PREFIX}.

Options:
``TARGET_NAME``
]]
function(install_target_to_prefix targetName)
    install(TARGETS ${targetName} DESTINATION ${CMAKE_INSTALL_PREFIX})
endfunction()

# ############################################################################################################
# Deps
# ############################################################################################################

# fetch_github("thezhe/CppConfigs@v0.9") # Adds opinionated linter/formatter/IDE/CI files to source directory.

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

# CppTemplateTest
add_executable(CppTemplateTest)
add_test(CppTemplateTest CppTemplateTest)
target_link_libraries(CppTemplateTest PRIVATE CppTemplate::libCppTemplate)

target_sources(CppTemplateTest PRIVATE test/CppTemplate/CppTemplateTest.cpp)

# ############################################################################################################
# Install
# ############################################################################################################

install_file_to_prefix(CHANGELOG.md)
install_target_to_prefix(CppTemplate)
