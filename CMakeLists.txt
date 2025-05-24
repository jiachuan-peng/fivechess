cmake_minimum_required(VERSION 3.30)
project(FiveChessGame_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FiveChessGame_master
    arcpaint.cpp
    arcpaint.h
    chessboard.cpp
    chessboard.h
    exitshow.cpp
    exitshow.h
    fivechess.cpp
    fivechess.h
    guize.cpp
    guize.h
    main.cpp
    showus.cpp
    showus.h
    welcome.cpp
    welcome.h)
