project(unixcoreclrloader)

add_compile_options(-fPIC)

include_directories(${CMAKE_SOURCE_DIR}/src/coreclr/hosts/unixcoreruncommon)
add_library(unixcoreclrloader
    STATIC
    coreclrloader.cpp
)

target_link_libraries(unixcoreclrloader
    unixcoreruncommon
)
