cmake_minimum_required(VERSION 3.13)
project(Caterpillars)

set(CMAKE_CXX_STANDARD 17)

add_executable(Caterpillars Entity.h Game.cpp Bullet.cpp Caterpillar.cpp Window.cpp main.cpp)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lSDL2")