#[[
Run a url as a CMake script.

    cmake -P <path-to-wrun.cmake> <url>

Fatal if: <url> content fails.
Dependencies: curl
]]

# See `execute_process` COMMAND_ERROR_IS_FATAL.
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

# Check dependencies.
execute_process(COMMAND curl --version OUTPUT_QUIET COMMAND_ERROR_IS_FATAL ANY)

# CLI
set(WRUN_URL "${CMAKE_ARGV3}")
set(WRUN_ARGC 4)
if(NOT WRUN_URL OR ${CMAKE_ARGC} GREATER ${WRUN_ARGC})
    message(FATAL_ERROR "Usage: cmake -P <path-to-wrun.cmake> <url>")
endif()

# Store <url> content in CURL_OUTPUT.
execute_process(
    COMMAND curl -fsSL "${WRUN_URL}"
    OUTPUT_VARIABLE CURL_OUTPUT ECHO_ERROR_VARIABLE COMMAND_ERROR_IS_FATAL ANY
)

# Run <url> contents.
cmake_language(EVAL CODE "${CURL_OUTPUT}")
