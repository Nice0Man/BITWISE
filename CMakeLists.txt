# CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(BITWISE LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add include directory
include_directories(include)

# Add source files
add_library(bitwise STATIC
    src/bitwise.c
    include/platform.h
    include/general.h
)

add_executable(bitwise_tests
    tests/test_bitwise.c
)

target_link_libraries(bitwise_tests bitwise)

# Set output directories
set_target_properties(bitwise PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(bitwise_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Enable optimizations
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(bitwise PRIVATE -O3)
endif()
