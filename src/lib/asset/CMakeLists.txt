file(GLOB_RECURSE ASSET_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(asset OBJECT ${ASSET_SRC})
target_include_directories(
    asset PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/SDL2/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_ttf
    ${CMAKE_SOURCE_DIR}/external/SDL2_image/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_INCLUDE_DIR}")
