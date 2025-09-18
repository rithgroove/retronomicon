message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")
file(GLOB_RECURSE ASSET_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-asset OBJECT ${ASSET_SRC})

target_include_directories(retronomicon-asset PUBLIC
    ${RETRO_DIR}/include
)

