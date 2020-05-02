cmake_minimum_required(VERSION 3.0.0)
include(GoogleTest)
file(GLOB_RECURSE SOURCE_LIST CONFIGURE_DEPENDS "*.cc")

add_executable(unit_tests ${SOURCE_LIST})
target_include_directories(unit_tests PRIVATE Utils ../src)
target_link_libraries(unit_tests PUBLIC
    gtest_main
    gmock_main
    src_lib
)
gtest_discover_tests(unit_tests)