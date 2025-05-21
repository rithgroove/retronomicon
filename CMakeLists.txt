cmake_minimum_required(VERSION 3.10)
project(retronomicon)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output folders
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add SDL2
add_subdirectory(external/SDL2)
include_directories(external/SDL2/include)

# Add header search path
include_directories(include)


# Your project sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    include/*.h
)

# Define executable
add_executable(retronomicon ${SOURCES})

# Link SDL2 statically
target_link_libraries(retronomicon SDL2)

# Optional: Add SDL2main if you're using it
# target_link_libraries(retronomicon SDL2main)

# On Windows, you might need this
if (WIN32)
    target_compile_definitions(retronomicon PRIVATE SDL_MAIN_HANDLED)
endif()