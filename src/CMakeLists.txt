# Collect engine modules
add_subdirectory(lib/asset)
add_subdirectory(lib/audio)
add_subdirectory(lib/core)
add_subdirectory(lib/graphic)
add_subdirectory(lib/input)
add_subdirectory(lib/math)
add_subdirectory(lib/scripting)

# Define library
add_library(retronomicon)

# Gather sources manually or dynamically (optional per-module globbing)
target_sources(retronomicon PRIVATE
    $<TARGET_OBJECTS:core>
    $<TARGET_OBJECTS:input>
    $<TARGET_OBJECTS:scripting>
)

target_include_directories(retronomicon
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(retronomicon
    PUBLIC SDL2 SDL2_ttf SDL2_image
)
