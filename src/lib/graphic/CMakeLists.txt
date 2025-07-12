file(GLOB_RECURSE GRAPHIC_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(graphic OBJECT ${GRAPHIC_SRC})
target_include_directories(
    graphic PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/SDL2/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_ttf/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_image/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_INCLUDE_DIR}")
