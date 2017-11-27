cmake_minimum_required(VERSION 3.8)
project(ex3)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES AIPlayer.cpp AIPlayer.h AvailableFinder.cpp AvailableFinder.h BoardManager.cpp BoardManager.h
        Checker.cpp Checker.h ConsolePlayer.cpp ConsolePlayer.h ConsolePrinter.cpp ConsolePrinter.h
        ex3.cpp GameManager.cpp GameManager.h Graphic.cpp Graphic.h Matrix.h Player.cpp Player.h Point.cpp Point.h
        RegularRules.cpp RegularRules.h Reversi.cpp Reversi.h)
add_executable(ex3 ${SOURCE_FILES})