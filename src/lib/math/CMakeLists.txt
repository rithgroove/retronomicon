file(GLOB_RECURSE MATH_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-math STATIC ${MATH_SRC})
target_include_directories(
    retronomicon-math PUBLIC
    ${RETRO_DIR}/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_DIR}")
