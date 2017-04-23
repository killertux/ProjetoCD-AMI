cmake_minimum_required(VERSION 2.6)
project(ami_server)

set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")

add_executable(ami_server main.cpp Server.cpp Client.cpp BELMP.cpp AMI.cpp)

#target_link_libraries()




install(TARGETS ami_server RUNTIME DESTINATION bin)
