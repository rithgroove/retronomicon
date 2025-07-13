file(GLOB_RECURSE ASSET_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(asset OBJECT ${ASSET_SRC})
target_include_directories(
    asset PUBLIC
    ${RETRO_DIR}/include
    ${RETRO_DIR}/external/SDL2/include
    ${RETRO_DIR}/external/SDL2_ttf
    ${RETRO_DIR}/external/SDL2_image/include
    ${RETRO_DIR}/external/SDL2_mixer/include
)
