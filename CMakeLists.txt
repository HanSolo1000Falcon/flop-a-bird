cmake_minimum_required(VERSION 4.1)
project(flop_a_bird)

set(CMAKE_CXX_STANDARD 26)
find_package(raylib REQUIRED)

add_executable(FlopABird src/main.cpp src/gamemanager.cpp
                         src/pipemanager.cpp src/pipe.cpp
                       )

target_include_directories(FlopABird PRIVATE include)
target_link_libraries(FlopABird PRIVATE raylib)
