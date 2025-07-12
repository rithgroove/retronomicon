cmake_minimum_required(VERSION 3.15)
project(retronomicon VERSION 0.1 LANGUAGES CXX)

# C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output folders
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(RETRO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "Retronomicon include path")

# Engine feature flags
option(ENABLE_LUA "Enable Lua scripting" ON)
option(ENABLE_PYTHON "Enable Python scripting" ON)

# External libraries
add_subdirectory(external/SDL2)
add_subdirectory(external/SDL2_ttf)
add_subdirectory(external/SDL2_image)

# Engine source (will add retronomicon library)
add_subdirectory(src)

# Public include paths
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/SDL2/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_ttf/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_image/include
)

# Optional: Message info
message(STATUS "Building retronomicon as a library ✅")
message(STATUS "Lua scripting: ${ENABLE_LUA}")
message(STATUS "Python scripting: ${ENABLE_PYTHON}")
