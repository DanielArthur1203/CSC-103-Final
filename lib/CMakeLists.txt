#Info on how to write this came from CMake docs
#https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library
add_library(lib STATIC 
    Game.cpp #Every time a new file is added to this folder need to include it's cpp file here
    Player.cpp
    Item.cpp
)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})