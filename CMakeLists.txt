# see https://github.com/tamaskenez/stackoverflow-cmake-find-link-example/blob/master/mylib/CMakeLists.txt
cmake_minimum_required(VERSION 3.1)
project(StopWatch VERSION 0.1)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -W -Weffc++ -Werror")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

add_subdirectory(lib)