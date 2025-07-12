file(GLOB_RECURSE AUDIO_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(audio OBJECT ${AUDIO_SRC})
target_include_directories(audio PUBLIC ${RETRO_DIR}/include)

