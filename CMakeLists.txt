cmake_minimum_required(VERSION 3.10)
project(retronomicon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# options
option(ENABLE_LUA    "Build Lua scripting"    ON)
option(ENABLE_PYTHON "Build Python scripting" ON)


# SDL2 and dependencies
add_subdirectory(external/SDL2)
add_subdirectory(external/SDL2_ttf)
add_subdirectory(external/SDL2_image)

if (ENABLE_LUA)
    include_directories(external/sol2/include)
    file(GLOB LUA_SRC external/lua-5.3.6/src/*.c)
    list(REMOVE_ITEM LUA_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/external/lua-5.3.6/src/lua.c
        ${CMAKE_CURRENT_SOURCE_DIR}/external/lua-5.3.6/src/luac.c)
    add_library(lua_static STATIC ${LUA_SRC})
    target_include_directories(lua_static PUBLIC external/lua-5.3.6/src)
    # target_sources(retronomicon PRIVATE src/scripting/LuaEngine.cpp)
    # target_compile_definitions(retronomicon PRIVATE USE_LUA=1)
endif()
if (NOT ENABLE_LUA)
    list(REMOVE_ITEM SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/scripting/lua_script_engine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/retronomicon/lib/scripting/lua_script_engine.h
    )
endif()

if (ENABLE_PYTHON)
    find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
    # add_subdirectory(external/pybind11)
    # target_sources(retronomicon PRIVATE src/scripting/PythonEngine.cpp)
    # target_compile_definitions(retronomicon PRIVATE USE_PYTHON=1)
endif()



# Project source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    include/*.h
)

# Define main executable
add_executable(retronomicon ${SOURCES})

target_include_directories(retronomicon PRIVATE include)

if (ENABLE_LUA)
    target_include_directories(retronomicon PRIVATE external/lua-5.3.6/src)

    # Include paths for your engine
    target_include_directories(retronomicon
        PRIVATE
            external/sol2/sol   # Adjust if needed
    )
    target_link_libraries(retronomicon PRIVATE lua_static)
    target_compile_definitions(retronomicon PRIVATE USE_LUA)
endif()


if (ENABLE_PYTHON)
    target_include_directories(retronomicon PRIVATE ${Python3_INCLUDE_DIRS})
    target_compile_definitions(retronomicon PRIVATE USE_PYTHON)

    target_link_libraries(retronomicon PRIVATE ${Python3_LIBRARIES})
endif()


# Link libraries
target_link_libraries(retronomicon
    PRIVATE
        SDL2 SDL2_ttf SDL2_image
)
# Windows-specific: disable SDL's main() override
if (WIN32)
    target_compile_definitions(retronomicon PRIVATE SDL_MAIN_HANDLED)
endif()
