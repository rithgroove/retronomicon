message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Collect engine modules
#add_subdirectory(lib)
#add_subdirectory(core)
#add_subdirectory(scene)
#add_subdirectory(asset)
#add_subdirectory(audio)
#add_subdirectory(input)
#add_subdirectory(engine)
#add_subdirectory(animation)
add_subdirectory(entity)
add_subdirectory(component)
add_subdirectory(math)

# Define the main retronomicon engine library
add_library(retronomicon)

# Link subsystem libraries
target_link_libraries(retronomicon
    PUBLIC
        retronomicon-entity
        retronomicon-component
        retronomicon-math
        #retronomicon-core
        #retronomicon-scene
        #retronomicon-asset
        #retronomicon-input
        #retronomicon-audio
        #retronomicon-engine
        #retronomicon-animation
)

# Global engine include path
target_include_directories(retronomicon
    PUBLIC ${RETRO_DIR}/include
)
