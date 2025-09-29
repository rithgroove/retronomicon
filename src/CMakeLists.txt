message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Collect engine modules
#add_subdirectory(lib)
add_subdirectory(core)
add_subdirectory(scene)
add_subdirectory(asset)
add_subdirectory(input)
add_subdirectory(animation)

# Define the main retronomicon engine library
add_library(retronomicon)

# Link subsystem libraries
target_link_libraries(retronomicon
    PUBLIC
        retronomicon-core
        retronomicon-scene
        retronomicon-asset
        retronomicon-input
        retronomicon-animation
)

# Global engine include path
target_include_directories(retronomicon
    PUBLIC ${RETRO_DIR}/include
)

# External dependencies (if needed)
# target_link_libraries(retronomicon
#     PUBLIC SDL2 SDL2_ttf SDL2_image SDL2_mixer
# )
