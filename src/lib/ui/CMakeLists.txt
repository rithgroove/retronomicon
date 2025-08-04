file(GLOB_RECURSE UI_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-ui STATIC ${UI_SRC})
target_include_directories(
    retronomicon-ui PUBLIC
    ${RETRO_DIR}/include
    ${RETRO_DIR}/external/SDL2/include
    ${RETRO_DIR}/external/SDL2_ttf/include
    ${RETRO_DIR}/external/SDL2_image/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_DIR}")
