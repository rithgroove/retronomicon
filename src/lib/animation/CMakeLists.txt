message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")
file(GLOB_RECURSE ANIMATION_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-animation OBJECT ${ANIMATION_SRC})

target_include_directories(retronomicon-animation PUBLIC
    ${RETRO_DIR}/include
)

