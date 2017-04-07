cmake_minimum_required(VERSION 2.6)
project(ami_server)

add_executable(ami_server main.cpp Server.cpp)

#target_link_libraries()

install(TARGETS ami_server RUNTIME DESTINATION bin)
