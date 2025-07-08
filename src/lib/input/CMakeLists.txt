file(GLOB_RECURSE INPUT_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(input OBJECT ${INPUT_SRC})
target_include_directories(input PUBLIC ${CMAKE_SOURCE_DIR}/include)

message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
