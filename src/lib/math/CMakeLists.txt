file(GLOB_RECURSE MATH_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(math OBJECT ${MATH_SRC})
target_include_directories(
    math PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
