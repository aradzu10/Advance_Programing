/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include <iostream>
using namespace std;
#include "Reversi.h"
#include "AIPlayer.h"
#include "ConsolePrinter.h"
#include "HumanPlayer.h"
#include "ServerLinker.h"

Reversi::Reversi(int size) : board_size(size), board(board_size), game(board) {
	ChangeSettings();
}

Reversi::~Reversi() {
}

void Reversi::ChangeSettings() {
	int task;
	cout << "Please choose type of opponent:" << endl;
	cout << "1 - AI player" << endl;
	cout << "2 - Both AI players" << endl;
	cout << "3 - Human player" << endl;
	cout << "4 - Online player" << endl;
	cin >> task;

	Graphic *printer;
	switch (task) {
		case 1:
			printer = new ConsolePrinter();
			game.SetPrinter(printer);
			game.SetPlayers(new ConsolePlayer(White, board, printer), new AIPlayer(Black, board, printer));
			break;
		case 2:
			printer = new ConsolePrinter();
			game.SetPrinter(printer);
			game.SetPlayers(new AIPlayer(White, board, printer), new AIPlayer(Black, board, printer));
			break;
		case 4:
			printer = new ConsolePrinter();
			game.SetPrinter(printer);
//			ServerLinker link()
			break;
		default:
			break;
	}
}

void Reversi::StartGame() {
	game.StartGame();
}