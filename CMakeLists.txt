cmake_minimum_required(VERSION 3.9)
project(StopWatch)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -W -Weffc++ -Werror")
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(StopWatch test/main.cpp src/StopWatch.cpp)
