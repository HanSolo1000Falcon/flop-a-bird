cmake_minimum_required(VERSION 4.1)
project(flop_a_bird)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
find_package(raylib REQUIRED)

add_executable(FlopABird src/main.cpp src/gamemanager.cpp
                         src/pipemanager.cpp src/pipe.cpp
                         src/bird.cpp
                       )

target_include_directories(FlopABird PRIVATE include)
target_link_libraries(FlopABird PRIVATE raylib)
