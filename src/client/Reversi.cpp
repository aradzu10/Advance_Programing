/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include <iostream>
#include <cstring>
#include <cstdio>

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
	switch (task) {
		case 1:
			SetupLocalGameWithAIPlayer();
			break;
		case 2:
			SetupLocalGameWithBothAIPlayer();
			break;
		case 4:
			SetupRemoteGame();
            break;
		default:
			break;
	}
}

void Reversi::SetupLocalGameWithAIPlayer() {
	Graphic *printer = new ConsolePrinter();
	game.SetPrinter(printer);
	game.SetPlayers(new HumanPlayer(White, printer), new AIPlayer(Black, board, printer));
}

void Reversi::SetupLocalGameWithBothAIPlayer() {
	Graphic *printer = new ConsolePrinter();
	game.SetPrinter(printer);
	game.SetPlayers(new AIPlayer(White, board, printer), new AIPlayer(Black, board, printer));
}

void Reversi::SetupRemoteGame() {
	ServerLinker *link = new ServerLinker();
	Graphic *printer = new ConsolePrinter();
	game.SetPrinter(printer);
	link->ConnectToServer();
	printer->PrintMessage("connected to server");
	ClientMenu(link, printer);

}

void Reversi::ClientMenu(ServerLinker *link, Graphic *printer) {
	char *tmp;
	while(link->isConnnectedToServer()) {
		printer->PrintMessage("Choose Option:");
		printer->PrintMessage("1. list games");
		printer->PrintMessage("2. join <game name>");
		printer->PrintMessage("3. start <game name>");
		string input = printer->GetDataFromUser();
		if (input.find("start") == 0 || input.find("join") == 0) {
			link->WriteDataToServer(input.c_str(), input.size());
			int size = link->ReadNumberFromServer();
            tmp = link->ReadDataFromServer(size);
			if (strcmp(tmp, "failed") == 0) {
				printer->PrintMessage("Operation failed!");
				delete tmp;
			} else {
				break;
			}
		} else if (input.find("list games") == 0) {
			int len;
			string gameList = "list_games";
			link->WriteDataToServer(gameList.c_str(), gameList.size());
			len = link->ReadNumberFromServer(); // get num of games
			if (len == 0) {
				printer->PrintMessage("There are no Games");
				continue;
			}
			for (int i = 0; i < len; i++) {
				int nameSize = link->ReadNumberFromServer();
				tmp = link->ReadDataFromServer(nameSize);
				string temp(tmp);
				printer->PrintMessage(temp);
				delete tmp;
			}
		} else {
			printer->PrintMessage("Invalid input!");
		}
	}
	printer->PrintMessage("waiting for opponent");
	if (strcmp(tmp, "success") == 0) {
		int num = link->ReadNumberFromServer();
		tmp = link->ReadDataFromServer(num);
	}
	if(!strcmp(tmp, "1")) {
		printer->PrintMessage("You are player X");
		game.SetPlayers(new RemotePlayerReceiver(White, printer, link),
						new RemotePlayerSender(link, new HumanPlayer(Black, printer)));
	} else {
		printer->PrintMessage("You are player O");
		game.SetPlayers(new RemotePlayerSender(link, new HumanPlayer(White, printer)),
						new RemotePlayerReceiver(Black, printer, link));
	}
	delete tmp;
}

void Reversi::StartGame() {
	game.StartGame();
}
