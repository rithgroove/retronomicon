message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Collect engine modules
#add_subdirectory(lib)
add_subdirectory(core)
add_subdirectory(scene)

# Define the main retronomicon engine library
add_library(retronomicon)

# Link subsystem libraries
target_link_libraries(retronomicon
    PUBLIC
        retronomicon-core-math
        retronomicon-core-ecs
        retronomicon-scene
)

# Global engine include path
target_include_directories(retronomicon
    PUBLIC ${RETRO_DIR}/include
)

# External dependencies (if needed)
# target_link_libraries(retronomicon
#     PUBLIC SDL2 SDL2_ttf SDL2_image SDL2_mixer
# )
