file(GLOB_RECURSE GRAPHIC_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-graphic OBJECT ${GRAPHIC_SRC})
target_include_directories(
    retronomicon-graphic PUBLIC
    ${RETRO_DIR}/include
    ${RETRO_DIR}/external/SDL2/include
    ${RETRO_DIR}/external/SDL2_ttf/include
    ${RETRO_DIR}/external/SDL2_image/include
)