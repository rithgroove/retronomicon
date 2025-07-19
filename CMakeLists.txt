cmake_minimum_required(VERSION 3.15)
project(retronomicon VERSION 0.1 LANGUAGES CXX)

# C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output folders
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(RETRO_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Retronomicon include path")
set(RETRO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "Retronomicon include path")

# Engine feature flags
option(ENABLE_LUA "Enable Lua scripting" ON)
option(ENABLE_PYTHON "Enable Python scripting" ON)

# External libraries
add_subdirectory(external/SDL2)
add_subdirectory(external/SDL2_ttf)
add_subdirectory(external/SDL2_image)
set(SDL2MIXER_OPUS OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_WAVPACK OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_FLAC OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_MIDI OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_MOD OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_MP3 OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_MPG123 OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_MOD_MODPLUG OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_MOD_XMP OFF CACHE BOOL "" FORCE)
set(SDL2MIXER_FLUIDSYNTH OFF CACHE BOOL "" FORCE)
# use STB vorbis
set(SDL2MIXER_VORBIS STB CACHE BOOL "" FORCE)
add_subdirectory(external/SDL2_mixer)
add_subdirectory(external/catch2)

# Engine source (will add retronomicon library)
add_subdirectory(src)

# Public include paths
include_directories(
    ${RETRO_INCLUDE_DIR}/include
    ${RETRO_INCLUDE_DIR}/external/SDL2/include
    ${RETRO_INCLUDE_DIR}/external/SDL2_ttf/include
    ${RETRO_INCLUDE_DIR}/external/SDL2_image/include
    ${RETRO_INCLUDE_DIR}/external/SDL2_mixer/include
    ${RETRO_INCLUDE_DIR}/external/catch2/src
)

add_subdirectory(tests)


# Optional: Message info
message(STATUS "Building retronomicon as a library ✅")
message(STATUS "Lua scripting: ${ENABLE_LUA}")
message(STATUS "Python scripting: ${ENABLE_PYTHON}")
