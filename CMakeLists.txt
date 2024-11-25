cmake_minimum_required(VERSION 3.10)
project(Microservicio)

set(CMAKE_CXX_STANDARD 17)

add_executable(microservicio main.cpp)

target_include_directories(microservicio PRIVATE /ruta/a/crow /ruta/a/json.hpp)
