cmake_minimum_required(VERSION 2.6)
project(ami_server)

add_executable(ami_server main.cpp)

install(TARGETS ami_server RUNTIME DESTINATION bin)
