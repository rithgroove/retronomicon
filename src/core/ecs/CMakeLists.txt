file(GLOB_RECURSE CORE_ECS_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(retronomicon-core-ecs OBJECT ${CORE_ECS_SRC})

target_include_directories(
    retronomicon-core-ecs PUBLIC
    ${RETRO_DIR}/include
)
