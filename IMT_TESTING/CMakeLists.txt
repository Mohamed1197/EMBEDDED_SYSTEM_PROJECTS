# CMake minimum version number requirements
cmake_minimum_required (VERSION 3.23.2)

# Project information
project ("TEST 1")

# Find all source files in the current directory
# And save the name to DIR_SRCS variable
aux_source_directory(. DIR_SRCS)

# Specify build target
add_executable(test1 ${DIR_SRCS})
