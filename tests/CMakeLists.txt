# tests/CMakeLists.txt

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS test_*.cpp)

add_executable(engine_tests ${TEST_SOURCES})

target_link_libraries(engine_tests
    PRIVATE
        retronomicon
        Catch2::Catch2WithMain
)

target_include_directories(engine_tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/external/catch2/src
        ${CMAKE_SOURCE_DIR}/external/SDL2/include
        ${CMAKE_SOURCE_DIR}/external/SDL2_ttf/include
        ${CMAKE_SOURCE_DIR}/external/SDL2_image/include
        ${CMAKE_SOURCE_DIR}/external/SDL2_mixer/include
)

include(Catch)
catch_discover_tests(engine_tests)

add_custom_command(TARGET engine_tests POST_BUILD
    COMMAND engine_tests
    COMMENT "🔍 Running unit tests after build..."
)