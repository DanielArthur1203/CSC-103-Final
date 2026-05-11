#Info on how to write this came from both GoogleTest docs and CMake
#https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library 
#https://google.github.io/googletest/quickstart-cmake.html

add_executable(tests tests.cpp)
target_link_libraries(tests 
    PRIVATE
    gtest_main
    lib
)

include(GoogleTest)
gtest_discover_tests(tests)