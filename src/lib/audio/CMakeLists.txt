file(GLOB_RECURSE AUDIO_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-audio OBJECT ${AUDIO_SRC})

target_include_directories(
    retronomicon-audio PUBLIC
    ${RETRO_DIR}/include
    ${RETRO_DIR}/external/SDL2/include
    ${RETRO_DIR}/external/SDL2_ttf
    ${RETRO_DIR}/external/SDL2_image/include
    ${RETRO_DIR}/external/SDL2_mixer/include
)
