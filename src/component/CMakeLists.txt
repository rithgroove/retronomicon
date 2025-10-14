file(GLOB_RECURSE COMPONENT_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-component OBJECT ${COMPONENT_SRC})
target_include_directories(
    retronomicon-component PUBLIC
    ${RETRO_DIR}/include
)