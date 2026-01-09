cmake_minimum_required(VERSION 3.10)
project(Proiect POO - La Biblioteca)

set(CMAKE_CXX_STANDARD 17)

# Adaugă fișierul sursă principal (ex: main.cpp)
add_executable(app 
    main.cpp
    biblioteca.cpp
    Carti.cpp
)
