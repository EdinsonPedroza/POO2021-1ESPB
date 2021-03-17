cmake_minimum_required(VERSION 3.19)
project(POSGSOFT)

set(CMAKE_CXX_STANDARD 20)

add_executable(POSGSOFT main.cpp Persona.h Acta.h Estudiante.h Director.h Jurado.h Acta.cpp Persona.cpp Director.cpp Jurado.cpp Estudiante.cpp)