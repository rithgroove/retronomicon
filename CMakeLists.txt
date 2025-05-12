cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_PREFIX_PATH /usr/bin/sdl2-config)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include headers
include_directories(include)

project(retronomicon VERSION 0.0.0 LANGUAGES CXX)

add_executable(retronomicon /src/main.cpp)

find_package(SDL2 REQUIRED)
target_link_libraries(retronomicon PRIVATE SDL2)

