/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include <iostream>
#include <cstring>

using namespace std;
#include "Reversi.h"
#include "AIPlayer.h"
#include "ConsolePrinter.h"
#include "HumanPlayer.h"
#include "ServerLinker.h"
#include "RemotePlayerSender.h"
#include "RemotePlayerReceiver.h"

Reversi::Reversi(int size) : board_size(size), board(board_size), game(board) {
	ChangeSettings();
}

Reversi::~Reversi() {
}

void Reversi::ChangeSettings() {
	int task;
	string temp;
	cout << "Please choose type of opponent:" << endl;
	cout << "1 - AI player" << endl;
	cout << "2 - Both AI players" << endl;
	cout << "3 - Human player" << endl;
	cout << "4 - Online player" << endl;
	cin >> task;
	getline(cin, temp);
	Graphic *printer;
	ServerLinker *link = new ServerLinker();
	char *tmp;
	switch (task) {
		case 1:
			printer = new ConsolePrinter();
			game.SetPrinter(printer);
			game.SetPlayers(new HumanPlayer(White, printer), new AIPlayer(Black, board, printer));
			break;
		case 2:
			printer = new ConsolePrinter();
			game.SetPrinter(printer);
			game.SetPlayers(new AIPlayer(White, board, printer), new AIPlayer(Black, board, printer));
			break;
		case 4:
			printer = new ConsolePrinter();
			game.SetPrinter(printer);
            link->ConnectToServer();
			std::cout << "connected to server" << std::endl;
			std::cout << "waiting for opponent" << std::endl;
			tmp = link->ReadDataFromServer();
            if(!strcmp(tmp, "1")) {
				game.SetPlayers(new RemotePlayerReceiver(White, printer, link),
								new RemotePlayerSender(link, new HumanPlayer(Black, printer)));
			} else {
				game.SetPlayers(new RemotePlayerSender(link, new HumanPlayer(White, printer)),
								new RemotePlayerReceiver(Black, printer, link));
			}
            delete tmp;
            break;
		default:
			break;
	}
}

void Reversi::StartGame() {
	game.StartGame();
}