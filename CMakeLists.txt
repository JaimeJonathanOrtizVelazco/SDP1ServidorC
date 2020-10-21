cmake_minimum_required(VERSION 3.17)
project(SDT1Servidor C)

set(CMAKE_C_STANDARD 99)

add_executable(SDT1Servidor main.c Socket_Servidor.h Socket.c Socket.h Socket_Servidor.c)