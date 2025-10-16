message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Collect engine modules
#add_subdirectory(lib)
#add_subdirectory(core)
#add_subdirectory(scene)
#add_subdirectory(audio)
#add_subdirectory(input)
#add_subdirectory(engine)
#add_subdirectory(animation)
add_subdirectory(entity)
add_subdirectory(component)
add_subdirectory(system)
add_subdirectory(manager)
add_subdirectory(math)
add_subdirectory(asset)

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
        #retronomicon-core
        #retronomicon-scene
        #retronomicon-input
        #retronomicon-audio
        #retronomicon-engine
        #retronomicon-animation
)

# Global engine include path
target_include_directories(retronomicon
    PUBLIC ${RETRO_DIR}/include
)
