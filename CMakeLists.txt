cmake_minimum_required(VERSION 3.24)
project(BTL)

set(CMAKE_CXX_STANDARD 14)

include_directories(BTL1)
include_directories(BTL1/__MACOSX)

add_executable(BTL
        BTL1/__MACOSX/._main.h
        BTL1/knight.cpp
        BTL1/knight.h
        BTL1/main.cpp
        BTL1/main.h)
