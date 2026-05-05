#Method of setting up CMake for google test and other library folders came from GoogleTest documentation
#https://google.github.io/googletest/quickstart-cmake.html
cmake_minimum_required(VERSION 3.50)  
project(FinalProject)

set(CMAKE_CXX_STANDARD 23) #needs this so to_underlying works as it makes enums easier to use
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) #For windows
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE lib)
set_target_properties(main PROPERTIES WIN32_EXECUTABLE OFF) #Again for Windows
