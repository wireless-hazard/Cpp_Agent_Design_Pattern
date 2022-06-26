cmake_minimum_required(VERSION 3.20)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_library(agent cpp_agents.cpp)
target_include_directories(agent PUBLIC ./)

set_property(TARGET agent PROPERTY CXX_STANDARD 11)
target_link_libraries(agent PUBLIC Threads::Threads)