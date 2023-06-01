cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(BadSorts)

add_executable(
  BadSorts
  src/main.cpp
  src/popl.hpp
  src/intervalTimer.hpp
  src/sorts.hpp
)