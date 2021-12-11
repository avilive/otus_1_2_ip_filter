# CMakeList.txt : CMake project for otus_1_2_ip_filter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (main)

set(SOURCES
    main.cpp 
)

add_executable(${PROJECT_NAME} main.cpp)

install(TARGETS main)

#target_link_libraries(MyApp libs)
target_link_libraries(${PROJECT_NAME}
    sub::lib1
)
# TODO: Add tests and install targets if needed.
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)