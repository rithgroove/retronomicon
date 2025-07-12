file(GLOB_RECURSE PHYSICS_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-physics STATIC ${PHYSICS_SRC})
target_include_directories(
    retronomicon-physics PUBLIC
    ${RETRO_DIR}/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_DIR}")
