file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(test_ip_filter ${SRCS})

TARGET_LINK_LIBRARIES(test_ip_filter
    libs
    libgtest
    libgmock
)

add_test(NAME test_ip_filter
         COMMAND test_ip_filter)
