cmake_minimum_required(VERSION 3.28)
project(MonstersAndDraftsmen)

set(CMAKE_CXX_STANDARD 17)

add_executable(MonstersVSDraftsmen
    src/main.cpp
    src/classes.cpp
    src/interpreter.cpp
    src/mazeGen.cpp
    src/moves.cpp
    src/saveLoad.cpp
)