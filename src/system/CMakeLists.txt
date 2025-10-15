file(GLOB_RECURSE SYSTEM_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-system OBJECT ${SYSTEM_SRC})
target_include_directories(
    retronomicon-system PUBLIC
    ${RETRO_DIR}/include
)