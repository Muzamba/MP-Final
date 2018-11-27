cmake_minimum_required(VERSION 3.6)   # CMake version check
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

include_directories(include)
include_directories(lib)
include_directories(source)
add_executable(Teste source/teste/testeGeraRecursos.cpp)
add_executable(Teste2 source/teste/testePlayer.cpp)
add_library(GeraRecursos source/GeraRecursos.cpp include/GeraRecursos.h source/Predio.cpp source/Objeto.cpp source/Unidade.cpp)
add_library(Predio source/Predio.cpp include/Predio.h)
add_library(Objeto source/Objeto.cpp include/Objeto.h)
add_library(Player source/Player.cpp include/Player.h)
add_library(Fabrica source/Fabrica.cpp include/Fabrica.h)
add_library(Jogo source/Jogo.cpp include/Jogo.h)
add_library(Botao source/Botao.cpp include/Botao.h)