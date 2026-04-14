cmake_minimum_required(VERSION 3.28)
project(MonstersVSDraftsmen VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(MonstersVSDraftsmen
    source/main.cpp
    source/includer.hpp
    source/classes.hpp
    source/classes.cpp
    #FileManager/
        source/FileManager/FileManager.hpp
        source/FileManager/load.cpp
        source/FileManager/save.cpp
        source/FileManager/numberofSavedGames.cpp
        source/FileManager/utils.cpp
    #Interface
        source/Interface/Interface.hpp
        source/Interface/getTheMoveofDr.cpp
        source/Interface/importer.cpp
        source/Interface/magicTransfer.cpp
        source/Interface/printer.cpp
        source/Interface/utils.cpp
    #MazeGenerator
        source/MazeGenerator/mazeGenerator.hpp
        source/MazeGenerator/mazeGenerator.cpp
        source/MazeGenerator/createTheSpanningTree.cpp
        source/MazeGenerator/placeTheChanceCubes.cpp
        source/MazeGenerator/placeTheDraftsmen.cpp
        source/MazeGenerator/placeTheLightSource.cpp
        source/MazeGenerator/placeTheMonsters.cpp
        source/MazeGenerator/placeTheWalls.cpp
        source/MazeGenerator/utils.cpp
    #Moves
        source/Moves/moves.hpp
        source/Moves/DraftsmanMove.cpp
        source/Moves/earthquake.cpp
        source/Moves/MonsterMove.cpp
        source/Moves/utils.cpp
)