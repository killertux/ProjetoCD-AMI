cmake_minimum_required(VERSION 2.6)
project(ami_client)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(AMI_Client_SRCS AMI_Client.cpp main.cpp ../AMI_Server/BELMP.cpp ../AMI_Server/AMI.cpp)

qt4_automoc(${AMI_Client_SRCS})
add_executable(ami_client ${AMI_Client_SRCS})
target_link_libraries(ami_client ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTNETWORK_LIBRARY})

install(TARGETS ami_client RUNTIME DESTINATION bin)
