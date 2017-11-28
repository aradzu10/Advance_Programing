cmake_minimum_required(VERSION 3.8)
project(ex3)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES src/AIPlayer.cpp src/AIPlayer_Test.h src/AvailableFinder.cpp src/AvailableFinder.h src/BoardManager.cpp src/BoardManager.h
        src/Checker.cpp src/Checker.h src/ConsolePlayer.cpp src/ConsolePlayer.h src/ConsolePrinter.cpp src/ConsolePrinter.h
        src/ex3.cpp src/GameManager.cpp src/GameManager.h src/Graphic.cpp src/Graphic.h src/Matrix.h src/Player.cpp
        src/Player.h src/Point.cpp src/Point.h src/RegularRules.cpp src/RegularRules.h src/Reversi.cpp src/Reversi.h)

add_executable(ex3 ${SOURCE_FILES} src/ex3.cpp)
add_executable(ReversiTests ${SOURCE_FILES} ${TEST_FILES} tests/gtest_main.cpp tests/TryTest.cpp tests/AIPlayer_Test.cpp tests/BoardManager_Test.cpp)
target_link_libraries(ReversiTests gtest gtest_main)
add_test(ReversiTests ReversiTests)