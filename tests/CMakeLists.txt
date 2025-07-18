# tests/CMakeLists.txt

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS test_*.cpp)

add_executable(engine_tests ${TEST_SOURCES})

target_link_libraries(engine_tests
    PRIVATE
        retronomicon
        Catch2::Catch2WithMain
)

target_include_directories(engine_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(Catch)
catch_discover_tests(engine_tests)
