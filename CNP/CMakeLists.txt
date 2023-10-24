cmake_minimum_required(VERSION 3.25.2)
project(CNP C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(libprg)

add_executable(CNP main.c)

target_link_libraries(CNP PUBLIC libprg)