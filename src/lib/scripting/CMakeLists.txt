file(GLOB_RECURSE SCRIPTING_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(scripting OBJECT ${SCRIPTING_SRC})
target_include_directories(scripting PUBLIC ${CMAKE_SOURCE_DIR}/include)

message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
