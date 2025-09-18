message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Add submodules inside lib/
add_subdirectory(ecs)
add_subdirectory(math)

# Define the main retronomicon engine library
add_library(retronomicon-core)

# Link subsystem libraries
target_link_libraries(retronomicon-core
    PUBLIC
        retronomicon-core-math
        retronomicon-core-ecs
)

# Later you can easily extend here:
# add_subdirectory(physics)
# add_subdirectory(audio)
