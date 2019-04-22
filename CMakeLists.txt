cmake_minimum_required(VERSION 3.13)
project(Caterpillars)

set(CMAKE_CXX_STANDARD 17)

add_executable(Caterpillars Entity.cpp Game.cpp Bullet.cpp Caterpillar.cpp Window.cpp KeyboardHandler.cpp Properties.h main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2")