find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)
set (CMAKE_CXX_STANDARD 11)
# Download and install GoogleTest
ExternalProject_Add(
    gtest
    #URL https://github.com/google/googletest/archive/master.zip
    GIT_REPOSITORY https://github.com/google/googletest.git
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
)


# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)
# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)
set(GTEST_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
 #Set libgtest properties
set_target_properties(libgtest PROPERTIES
   # "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LOCATION" "${binary_dir}/lib/gtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

add_subdirectory(test_ip_filter)
