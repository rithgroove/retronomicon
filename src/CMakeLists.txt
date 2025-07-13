message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Collect engine modules
add_subdirectory(lib/animation)
add_subdirectory(lib/asset)
add_subdirectory(lib/audio)
add_subdirectory(lib/core)
add_subdirectory(lib/graphic)
add_subdirectory(lib/input)
add_subdirectory(lib/math)
add_subdirectory(lib/scripting)
add_subdirectory(lib/physics)

# Define the main retronomicon engine library
add_library(retronomicon)

# Add object sources from each subsystem
target_sources(retronomicon
    PRIVATE
        $<TARGET_OBJECTS:retronomicon-animation>
        $<TARGET_OBJECTS:core>
        $<TARGET_OBJECTS:retronomicon-input>
        $<TARGET_OBJECTS:scripting>
        $<TARGET_OBJECTS:asset>
        $<TARGET_OBJECTS:audio>
        $<TARGET_OBJECTS:retronomicon-graphic>
        $<TARGET_OBJECTS:retronomicon-math>
        $<TARGET_OBJECTS:retronomicon-physics>
)

# Global engine include path
target_include_directories(retronomicon
    PUBLIC ${RETRO_DIR}/include
)

# Link external dependencies
target_link_libraries(retronomicon
    PUBLIC SDL2 SDL2_ttf SDL2_image SDL2_mixer
)

include_directories(
    ${RETRO_DIR}/include
    ${RETRO_DIR}/external/SDL2/include
    ${RETRO_DIR}/external/SDL2_ttf/include
    ${RETRO_DIR}/external/SDL2_image/include
    ${RETRO_DIR}/external/SDL2_mixer/include
)