file(GLOB_RECURSE ENTITY_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-entity OBJECT ${ENTITY_SRC})
target_include_directories(
    retronomicon-entity PUBLIC
    ${RETRO_DIR}/include
)