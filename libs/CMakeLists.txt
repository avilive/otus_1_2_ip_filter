# CMakeList.txt : CMake project for otus_1_2_ip_filter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(libs
    ip_filter.cpp 
    ip_filter.h
)

add_library(libs STATIC ${libs})

target_include_directories(libs PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(libs PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# TODO: Add tests and install targets if needed.
