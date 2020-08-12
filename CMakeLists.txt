# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("otus_1_2_ip_filter")

# Include sub-projects.
add_subdirectory ("libs")
add_subdirectory ("main")
#add_subdirectory ("test")


