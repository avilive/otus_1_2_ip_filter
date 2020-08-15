# CMakeList.txt : CMake project for otus_1_2_ip_filter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(SOURCES
    main.cpp 
)

add_executable(MyApp ${SOURCES})

target_link_libraries(MyApp libs)
# TODO: Add tests and install targets if needed.
set_target_properties(MyApp  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)