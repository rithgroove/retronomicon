message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Add submodules inside lib/
add_subdirectory(ecs)

# Later you can easily extend here:
# add_subdirectory(physics)
# add_subdirectory(audio)
