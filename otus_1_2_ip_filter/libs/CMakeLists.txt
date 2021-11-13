# CMakeList.txt : CMake project for otus_1_2_ip_filter, include source and define
# project specific logic here.
#
project (sublibrary1)
#cmake_minimum_required (VERSION 3.8)

#set(libs
 #   ip_filter.cpp 
    #ip_filter.h
#)

add_library(${PROJECT_NAME} src/ip_filter.cpp)
add_library(sub::lib1 ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

#set_target_properties(libs PROPERTIES
#    CXX_STANDARD 14
#    CXX_STANDARD_REQUIRED ON
#)

# TODO: Add tests and install targets if needed.
