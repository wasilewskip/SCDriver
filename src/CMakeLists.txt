file(GLOB_RECURSE HEADER_LIST CONFIGURE_DEPENDS "*.h")
file(GLOB_RECURSE SOURCE_LIST CONFIGURE_DEPENDS "*.cc")

add_library(src_lib ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(src_lib PRIVATE .)