file(GLOB_RECURSE SCRIPTING_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-scripting OBJECT ${SCRIPTING_SRC})
target_include_directories(
    retronomicon-scripting PUBLIC
    ${RETRO_DIR}/include
    ${RETRO_DIR}/external/SDL2/include
    ${RETRO_DIR}/external/SDL2_ttf/include
    ${RETRO_DIR}/external/SDL2_image/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_DIR}")
