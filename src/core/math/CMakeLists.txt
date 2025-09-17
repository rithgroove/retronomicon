file(GLOB_RECURSE MATH_CORE_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-core-math STATIC ${MATH_CORE_SRC})
target_include_directories(
    retronomicon-core-math PUBLIC
    ${RETRO_DIR}/include
)

message("CMAKE_SOURCE_DIR = ${RETRO_DIR}")
