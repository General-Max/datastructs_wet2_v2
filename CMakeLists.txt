cmake_minimum_required(VERSION 3.21)
project(wet2_v2)

set(CMAKE_C_STANDARD 14)

include_directories(.)

add_executable(wet2
        Team.cpp
        Team.h
        Node.h
        Node.cpp
        HashMap.h
        UnionFind.h
        UnionFind.cpp
        HashMap.cpp
        Array.h
        AVLRankTree.h
        DynamicArray.h
        main.cpp
        Player.cpp
        Player.h
        sortRegular.cpp
        sortRegular.h
        SortByAbility.h
        SortByAbility.cpp
        SortTeamById.h
        SortTeamById.cpp
        wet2util.h
        worldcup23a2.cpp
        worldcup23a2.h)
