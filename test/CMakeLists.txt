cmake_minimum_required(VERSION 3.1)
project(StopWatchTest)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -W -Weffc++ -Werror")
set(CMAKE_CXX_STANDARD 14)

include_directories(../include)

add_executable(StopWatchTest test.cpp ../src/StopWatch.cpp)
