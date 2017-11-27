/*
Name: Arad Zulti
ID: 315240564
*/

#include <iostream>
using namespace std;
#include "Reversi.h"
#include "AIPlayer.h"
#include "ConsolePrinter.h"
#include "Graphic.h"

Reversi::Reversi(int size) : board_size(size), board(board_size), game(board_size, board) {
	ChangeSettings();
}

Reversi::~Reversi() {
}

void Reversi::ChangeSettings() {
	int task;
	cout << "Please choose type of opponent:" << endl;
	cout << "1 - AI player" << endl;
	cout << "2 - Human player" << endl;
	cin >> task;
	if (task == 1) {
		Graphic *printer = new ConsolePrinter();
		game.SetPrinter(printer);
		game.SetPlayers(new AIPlayer(White, board, printer), new AIPlayer(Black, board, printer));
	}
}

void Reversi::StartGame() {
	game.StartGame();
}