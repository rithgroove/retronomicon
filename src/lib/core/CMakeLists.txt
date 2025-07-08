file(GLOB_RECURSE CORE_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(core OBJECT ${CORE_SRC})
target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)

message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
