file(GLOB_RECURSE GRAPHIC_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(graphic OBJECT ${GRAPHIC_SRC})
target_include_directories(graphic PUBLIC ${CMAKE_SOURCE_DIR}/include)

message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
