cmake_minimum_required(VERSION 3.10)
project(SerraIntelligente)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SerraIntelligente
        main.cpp
        src/Orario.cpp
        src/Impianto.cpp
        src/ImpiantoTropicale.cpp
        src/ImpiantoDesertico.cpp
        src/ImpiantoMediterraneo.cpp
        src/ImpiantoAlpino.cpp
        src/ImpiantoCarnivoro.cpp
        src/Serra.cpp
        include/Orario.h
        src/Orario.cpp
        include/Impianto.h
        src/Impianto.cpp
        src/ImpiantoTropicale.cpp
        include/ImpiantoTropicale.h
        src/ImpiantoDesertico.cpp
        include/ImpiantoDesertico.h
        src/ImpiantoMediterraneo.cpp
        include/ImpiantoMediterraneo.h
        src/ImpiantoAlpino.cpp
        include/ImpiantoAlpino.h
        src/ImpiantoCarnivoro.cpp
        include/ImpiantoCarnivoro.h
        src/Serra.cpp
        include/Serra.h
)

target_include_directories(SerraIntelligente PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})