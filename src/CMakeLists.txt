message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Collect engine modules
#add_subdirectory(lib)
#add_subdirectory(core)
add_subdirectory(entity)
add_subdirectory(component)
add_subdirectory(system)
add_subdirectory(manager)
add_subdirectory(math)
add_subdirectory(asset)
add_subdirectory(animation)
add_subdirectory(input)
add_subdirectory(engine)
add_subdirectory(audio)
add_subdirectory(scene)

# Define the main retronomicon engine library
add_library(retronomicon)

# Link subsystem libraries
target_link_libraries(retronomicon
    PUBLIC
        retronomicon-entity
        retronomicon-component
        retronomicon-system
        retronomicon-manager
        retronomicon-math
        retronomicon-asset
        retronomicon-animation
        retronomicon-input
        retronomicon-scene
        retronomicon-audio
        retronomicon-engine
)

# Global engine include path
target_include_directories(retronomicon
    PUBLIC ${RETRO_DIR}/include
)
