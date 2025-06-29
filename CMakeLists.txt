cmake_minimum_required(VERSION 3.10)
project(retronomicon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# SDL2 and dependencies
add_subdirectory(external/SDL2)
add_subdirectory(external/SDL2_ttf)
add_subdirectory(external/SDL2_image)

# sol2: header-only — DO NOT use add_subdirectory
include_directories(external/optional/include)
include_directories(external/sol2/include)
include_directories(external)# or adjust path to match your sol2 structure

# Lua static library
file(GLOB LUA_SRC
    external/lua-5.3.6/src/*.c
)

# EXCLUDE `lua.c` and `luac.c` — those are CLI frontends
list(REMOVE_ITEM LUA_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/external/lua-5.3.6/src/lua.c
    ${CMAKE_CURRENT_SOURCE_DIR}/external/lua-5.3.6/src/luac.c
)

add_library(lua_static STATIC ${LUA_SRC})
target_include_directories(lua_static PUBLIC external/lua-5.3.6/src)

# Project source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    include/*.h
)

# Define main executable
add_executable(retronomicon ${SOURCES})

target_include_directories(retronomicon PRIVATE external/lua-5.3.6/src)

# Include paths for your engine
target_include_directories(retronomicon
    PRIVATE
        include
        external/sol2/sol   # Adjust if needed
)



# Link libraries
target_link_libraries(retronomicon
    PRIVATE
        SDL2 SDL2_ttf SDL2_image
)
target_link_libraries(retronomicon PRIVATE lua_static)

# Windows-specific: disable SDL's main() override
if (WIN32)
    target_compile_definitions(retronomicon PRIVATE SDL_MAIN_HANDLED)
endif()
