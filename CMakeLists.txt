cmake_minimum_required(VERSION 3.10)

project(cpp11Threads)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(agent cpp_agents.cpp)

set_property(TARGET agent PROPERTY CXX_STANDARD 11)
target_link_libraries(agent PRIVATE Threads::Threads)