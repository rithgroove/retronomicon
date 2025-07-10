# Collect engine modules
add_subdirectory(lib/asset)
add_subdirectory(lib/audio)
add_subdirectory(lib/core)
add_subdirectory(lib/graphic)
add_subdirectory(lib/input)
add_subdirectory(lib/math)
add_subdirectory(lib/scripting)

# Define the main retronomicon engine library
add_library(retronomicon)

# Add object sources from each subsystem
target_sources(retronomicon
    PRIVATE
        $<TARGET_OBJECTS:core>
        $<TARGET_OBJECTS:input>
        $<TARGET_OBJECTS:scripting>
        $<TARGET_OBJECTS:asset>
        $<TARGET_OBJECTS:audio>
        $<TARGET_OBJECTS:graphic>
        $<TARGET_OBJECTS:input>
        $<TARGET_OBJECTS:math>
)

# Global engine include path
target_include_directories(retronomicon
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

# Link external dependencies
target_link_libraries(retronomicon
    PUBLIC SDL2 SDL2_ttf SDL2_image
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/SDL2/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_ttf/include
    ${CMAKE_SOURCE_DIR}/external/SDL2_image/include
)
# Define engine-wide compile definitions
if (ENABLE_LUA)
    target_compile_definitions(retronomicon PUBLIC USE_LUA)
endif()

if (ENABLE_PYTHON)
    target_compile_definitions(retronomicon PUBLIC USE_PYTHON)
endif()