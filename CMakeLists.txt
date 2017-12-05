cmake_minimum_required(VERSION 3.8)
project(ex3)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CLIENT_SOURCE_FILES src/client/AIPlayer.cpp src/client/AIPlayer_Test.h src/client/AvailableFinder.cpp src/client/AvailableFinder.h src/client/BoardManager.cpp
        src/client/BoardManager.h src/client/Checker.cpp src/client/Checker.h src/client/ConsolePlayer.cpp src/client/ConsolePlayer.h src/client/ConsolePrinter.cpp
        src/client/ConsolePrinter.h src/client/ClientMain.cpp src/client/GameManager.cpp src/client/GameManager.h src/client/Graphic.cpp src/client/Graphic.h src/client/Matrix.h
        src/client/Player.cpp src/client/Player.h src/client/Point.cpp src/client/Point.h src/client/RegularRules.cpp src/client/RegularRules.h src/client/Reversi.cpp
        src/client/Reversi.h src/client/ServerLinker.cpp src/client/ServerLinker.h)

set(SERVER_SOURCE_FILE src/server/Server.cpp src/server/Server.h)

set(TEST_FILES tests/Temp.cpp tests/AIPlayer_Test.cpp tests/BoardManager_Test.cpp tests/RegularRule_Test.cpp
        tests/ConsolePrinter_Test.cpp)

add_executable(Reversi ${CLIENT_SOURCE_FILES} src/client/ClientMain.cpp)
add_executable(Server ${SERVER_SOURCE_FILE} src/server/ServerMain.cpp)
add_executable(ReversiTests ${CLIENT_SOURCE_FILES} ${TEST_FILES} tests/gtest_main.cpp)
target_link_libraries(ReversiTests gtest gtest_main)
add_test(ReversiTests ReversiTests)