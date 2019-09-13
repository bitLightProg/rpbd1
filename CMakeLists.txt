cmake_minimum_required(VERSION 3.13)
project(rpbd1)

set(CMAKE_CXX_STANDARD 17)

add_executable(rpbd1 main.cpp)
target_link_libraries(rpbd1 libodbc32.a)