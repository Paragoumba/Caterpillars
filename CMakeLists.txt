cmake_minimum_required(VERSION 3.13)
project(Caterpillars)

set(CMAKE_CXX_STANDARD 17)

add_executable(Caterpillars TextureHandler.cpp Utils.cpp Entity.cpp Game.cpp Bullet.cpp Caterpillar.cpp Window.cpp KeyboardHandler.cpp Properties.cpp main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2 -lSDL2_ttf")