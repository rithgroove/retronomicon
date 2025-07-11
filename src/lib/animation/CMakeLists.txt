file(GLOB_RECURSE ANIMATION_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(animation OBJECT ${ANIMATION_SRC})
target_include_directories(
    animation PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/SDL2/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_ttf/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_image/include
)

message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
