cmake_minimum_required(VERSION 3.9)
project(ex2)

find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

set(CMAKE_CXX_STANDARD 11)

add_executable(ex2 ex2.cpp AuthorIdentify.cc AuthorIdentify.h)