file(GLOB_RECURSE CORE_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(core OBJECT ${CORE_SRC})
#target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)


target_include_directories(
    core PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/SDL2/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_ttf/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_image/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_INCLUDE_DIR}")
