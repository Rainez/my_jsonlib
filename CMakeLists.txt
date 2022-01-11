cmake_minimum_required(VERSION 3.21)
project(raineTop) #每次使用模版工程新建项目都要修改这里的字段
set(CMAKE_CXX_STANDARD 20)
file(GLOB SRC_FILE *.cpp *.hpp)
add_executable(${PROJECT_NAME} ${SRC_FILE})
