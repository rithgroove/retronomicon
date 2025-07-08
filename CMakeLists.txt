cmake_minimum_required(VERSION 3.15)
project(retronomicon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Build options
option(ENABLE_LUA "Enable Lua scripting" ON)
option(ENABLE_PYTHON "Enable Python scripting" ON)

# Add SDL & dependencies
add_subdirectory(external/SDL2)
add_subdirectory(external/SDL2_ttf)
add_subdirectory(external/SDL2_image)

# Add retronomicon source
add_subdirectory(src)
