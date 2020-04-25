cmake_minimum_required(VERSION 3.0.0)

set(SOURCES
    FirstTest.cpp
)

add_executable(testas ${SOURCES})
target_link_libraries(testas PUBLIC
    gtest_main
    gmock_main
)

add_test(
    NAME testas
    COMMAND testas
)