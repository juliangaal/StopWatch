cmake_minimum_required(VERSION 3.1)
project(SOME)

set(CMAKE_CXX_STANDARD 11)

find_package(StopWatch 0.1 REQUIRED)

add_executable(StopWatchTest src/stopwatch_test.cpp ../lib/src/StopWatch.cpp)
target_compile_options(StopWatchTest PRIVATE -Wall -Wextra -Wpedantic)

add_executable(StopWatchImportTest src/import_test.cpp)
target_compile_options(StopWatchImportTest PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(StopWatchImportTest PUBLIC StopWatch)