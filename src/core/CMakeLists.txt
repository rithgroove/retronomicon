message(STATUS "==== Processing ${CMAKE_CURRENT_LIST_FILE} ====")

# Add submodules inside lib/
add_subdirectory(ecs)
add_subdirectory(math)

# Later you can easily extend here:
# add_subdirectory(physics)
# add_subdirectory(audio)
