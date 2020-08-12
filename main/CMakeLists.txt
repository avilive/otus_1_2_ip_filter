# CMakeList.txt : CMake project for otus_1_2_ip_filter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(SOURCES
    main.cpp 
)

add_executable(main.cpp ${SOURCES})

target_link_libraries(main.cpp libs)
# TODO: Add tests and install targets if needed.
set_target_properties(main.cpp  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)