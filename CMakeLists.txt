cmake_minimum_required(VERSION 3.10)

project(cpp11Threads)
list(APPEND CMAKE_CXX_FLAGS "-pthread -std=c++11 ${CMAKE_CXX_FLAGS}")
add_executable(agent cpp_agents.cpp)