cmake_minimum_required(VERSION 3.1)
project(SOME)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -W -Weffc++ -Werror")
set(CMAKE_CXX_STANDARD 14)

find_package(StopWatch 0.1 REQUIRED)
include_directories({STOPWATCH_INCLUDE_DIR})

add_executable(StopWatchTest src/stopwatch_test.cpp)
target_link_libraries(StopWatchTest PUBLIC StopWatch)

add_executable(StopWatchImportTest src/import_test.cpp)
target_link_libraries(StopWatchImportTest PUBLIC StopWatch)