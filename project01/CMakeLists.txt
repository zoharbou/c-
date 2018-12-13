cmake_minimum_required(VERSION 3.9)
project(project01)

set(CMAKE_CXX_STANDARD 17)

add_executable(project01 tester.cpp Vector3D.cc Vector3D.h Matrix3D.cc Matrix3D.h)