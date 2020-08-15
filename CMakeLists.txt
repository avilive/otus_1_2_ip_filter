# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)


set(HEADER_FILE "build_number.h")
set(CACHE_FILE "BuildNumberCache.txt")

#Reading data from file + incrementation
IF(EXISTS ${CACHE_FILE})
    file(READ ${CACHE_FILE} BUILD_NUMBER)
    math(EXPR BUILD_NUMBER "${BUILD_NUMBER}+1")
ELSE()
    set(BUILD_NUMBER "1")
ENDIF()

project ("otus_1_2_ip_filter" VERSION 0.0.${BUILD_NUMBER})

# Include sub-projects.
add_subdirectory ("libs")
add_subdirectory ("main")
#add_subdirectory ("test")




set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
