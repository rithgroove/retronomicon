#!/bin/bash

# Exit on any error
set -e

# Clean build folder
rm -rf build
mkdir build && cd build

# Configure CMake
cmake ..

# Build the test executable
make engine_tests

# Run it
./build/bin/engine_tests
