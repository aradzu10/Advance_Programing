/*
Name: Arad Zulti
ID: 315240564
*/

#include "Reversi.h"
#include "GameManager.h"
#include "ConsolePlayer.h"
#include "AIPlayer.h"
#include "BoardManager.h"
#include "ConsolePrinter.h"
#include "RegularRules.h"
#include "Graphic.h"

Reversi::Reversi(int size) : board_size(size), board(board_size), game(board_size, board) {
	ChangeSettings();
}

Reversi::~Reversi() {
}

void Reversi::ChangeSettings() {
	Graphic* printer = new ConsolePrinter();
	game.SetPrinter(printer);
	game.SetPlayers(new AIPlayer(White, board, printer), new AIPlayer(Black, board, printer));
}

void Reversi::StartGame() {
	game.StartGame();
}