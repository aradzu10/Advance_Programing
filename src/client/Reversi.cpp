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


}

void Reversi::ClientMenu(ServerLinker *link, Graphic *printer) {
	char *tmp;
	while(true) {
		printer->PrintMessage("Choose Option:");
		printer->PrintMessage("\tShow all games enter \"game list\"");
		printer->PrintMessage("\tTo Join game enter \"join <game name>\"");
		printer->PrintMessage("\tTo start new game enter \"start <game name>\"");
		string input = printer->GetDataFromUser();
		if (input.find("start") == 0 || input.find("join") == 0 || input.find("close") == 0) {
			link->WriteDataToServer(input.c_str(), input.size());
			break;
		} else if (input.find("game list") == 0) {
			int len;
			string gameList = "game_list";
			link->WriteDataToServer(gameList.c_str(), gameList.size());
			tmp = link->ReadDataFromServer(); // get num of games
			if (strcmp(tmp, "0") == 0) {
				printer->PrintMessage("There are no Games");
				continue;
			}
			sscanf(tmp, "%d", &len);
			delete tmp;
			for (int i = 0; i < len; i++) {
				tmp = link->ReadDataFromServer();
				string temp(tmp);
				printer->PrintMessage(temp);
				delete tmp;
			}
		} else {
			printer->PrintMessage("Invalid input!");
		}
	}
	printer->PrintMessage("waiting for opponent");
	tmp = link->ReadDataFromServer();
	if(!strcmp(tmp, "1")) {
		game.SetPlayers(new RemotePlayerReceiver(White, printer, link),
						new RemotePlayerSender(link, new HumanPlayer(Black, printer)));
	} else {
		game.SetPlayers(new RemotePlayerSender(link, new HumanPlayer(White, printer)),
						new RemotePlayerReceiver(Black, printer, link));
	}
	delete tmp;
}

void Reversi::StartGame() {
	game.StartGame();
}
