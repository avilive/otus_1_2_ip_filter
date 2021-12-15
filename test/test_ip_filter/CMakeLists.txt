
enable_testing()
file(GLOB SRCS *.cpp)
ADD_EXECUTABLE(test_ip_filter ${SRCS})

#add_executable(
#  hello_test
#  hello_test.cc
#)

TARGET_LINK_LIBRARIES(test_ip_filter
    sub::lib1
    libgtest
    libgmock
)

include(GoogleTest)
gtest_discover_tests(hello_test)
