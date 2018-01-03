# ID: 318439981
# Name: Matan Dombelski
# ID: 315240564
# Name: Arad Zulti


makeEXE: makeEXEGame makeEXEServer

makeEXEGame: compileGame
	g++ *.o -o exe/Reversi.out
	rm -f *.o

makeEXEServer: compileServer
	g++ *.o -o exe/Server.out -pthread
	rm -f *.o

compileGame: src/connectionSetting/*.h src/connectionSetting/*.cpp src/client/*.h src/client/*.cpp
	g++ -c src/connectionSetting/*.cpp src/client/*.cpp

compileServer: src/connectionSetting/*.h src/connectionSetting/*.cpp src/server/*.h src/server/*.cpp
	g++ -c src/connectionSetting/*.cpp src/server/*.cpp -pthread
