file(GLOB_RECURSE SCRIPTING_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(scripting OBJECT ${SCRIPTING_SRC})
target_include_directories(
    scripting PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/SDL2/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_ttf/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_image/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_INCLUDE_DIR}")
