cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS -pthread)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CLIENT_SOURCE_FILES src/client/AIPlayer.cpp src/client/AIPlayer.h src/client/AvailableFinder.cpp
        src/client/AvailableFinder.h src/client/BoardManager.cpp src/client/BoardManager.h src/client/Checker.cpp
        src/client/Checker.h src/client/HumanPlayer.cpp src/client/HumanPlayer.h src/client/ConsolePrinter.cpp
        src/client/ConsolePrinter.h src/client/GameManager.cpp src/client/GameManager.h
        src/client/Graphic.cpp src/client/Graphic.h src/client/Matrix.h src/client/Player.cpp src/client/Player.h
        src/client/Point.cpp src/client/Point.h src/client/RegularRules.cpp src/client/RegularRules.h
        src/client/Reversi.cpp src/client/Reversi.h src/client/ServerLinker.cpp src/client/ServerLinker.h
        src/client/RemotePlayerReceiver.cpp src/client/RemotePlayerReceiver.h src/client/RemotePlayerSender.cpp
        src/client/RemotePlayerSender.h src/connectionSetting/ConnectionSettings.cpp src/connectionSetting/ConnectionSettings.h)

set(SERVER_SOURCE_FILE src/server/MatchHandler.cpp src/server/MatchHandler.h src/connectionSetting/ConnectionSettings.cpp
        src/connectionSetting/ConnectionSettings.h src/server/Server.cpp src/server/Server.h src/server/CommandManager.cpp
        src/server/CommandManager.h src/server/Command.cpp src/server/Command.h src/server/MatchManager.cpp
        src/server/MatchManager.h src/server/CommandGamesList.cpp src/server/CommandGamesList.h src/server/CommandStart.cpp
        src/server/CommandStart.h src/server/CommandJoin.cpp src/server/CommandJoin.h src/server/CommandClose.cpp
        src/server/CommandClose.h)

set(TEST_FILES src/client/tests/Temp.cpp src/client/tests/AIPlayer.cpp src/client/tests/BoardManager_Test.cpp
        src/client/tests/RegularRule_Test.cpp src/client/tests/ConsolePrinter_Test.cpp)

add_executable(Reversi ${CLIENT_SOURCE_FILES} src/client/PlayReversi.cpp)
add_executable(Server ${SERVER_SOURCE_FILE} src/server/ServerMain.cpp)
add_executable(ReversiTests ${CLIENT_SOURCE_FILES} ${TEST_FILES} src/client/tests/gtest_main.cpp)
target_link_libraries(ReversiTests gtest gtest_main)
add_test(ReversiTests ReversiTests)