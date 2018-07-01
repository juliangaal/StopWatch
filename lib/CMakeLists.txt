cmake_minimum_required(VERSION 3.1)
project(StopWatch)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -W -Weffc++ -Werror")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_PREFIX /usr/local)

#include_directories(include)
#add_library(StopWatch STATIC src/StopWatch.cpp)
#
#install(FILES include/StopWatch.hpp
#        DESTINATION include/StopWatch)
#install(TARGETS StopWatch
#        DESTINATION lib/StopWatch
#        EXPORT StopWatchConfig)
#install(EXPORT StopWatchConfig
#        DESTINATION lib/cmake/StopWatch)

