/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "GameManager.h"
#include "ConsolePlayer.h"
#include "ConsolePrinter.h"

GameManager::GameManager(BoardManager& board_) : board(board_) {
	printer = new ConsolePrinter();
	white = new ConsolePlayer(White, board, printer);
	black = new ConsolePlayer(Black, board, printer);
}

void GameManager::SetPrinter(Graphic* printer_) {
	if (printer)
		delete printer;
	printer = printer_;
}

void GameManager::SetPlayers(Player * white_, Player * black_) {
	if (white)
		delete white;
	white = white_;
	if (black)
		delete black;
	black = black_;
}

GameManager::~GameManager() {
	if (printer)
		delete printer;
	if (white)
		delete white;
	if (black)
		delete black;
}

void GameManager::StartGame() {
	Checker player = White;
	while (true) {
		board.FindAllAvailable();
		printer->PrintBoard(board.GetBoard(), board.GetSize());
		printer->PrintTurnOf(player);
		if (!board.CheckPlayerAvailable(player)) {
			printer->PrintMessage("You don't have any available moves...");
			if (board.CheckIfGameEnded()) {
				player = board.ReturnWinner();
				if (player == Nothing) {
					printer->PrintMessage("It's a tie!");
				} else {
					printer->PrintWinnerMessage(player);
				}
				break;
			}
			printer->PrintMessage("Turn go to next player");
			player = GetOppsiteChecker(player);
			continue;
		}
		printer->PrintAvilable(board.GetBoard(), board.GetSize(), GetAvailableChecker(player));
		Point tmp = GetPointFromPlayer(player);
		while (!board.DoTurn(tmp.getRow(), tmp.getCol(), player)) {
			tmp = GetPointFromPlayerAgain(player);
		}
		player = GetOppsiteChecker(player);
	}
}

Point GameManager::GetPointFromPlayer(Checker color) {
	if (color == Black) {
		return black->GetPointFromPlayer();
	}
	if (color == White) {
		return white->GetPointFromPlayer();
	}
	return Point(-1, -1);
}

Point GameManager::GetPointFromPlayerAgain(Checker color) {
	if (color == Black) {
		return black->PointIsntAvialabe();
	}
	if (color == White) {
		return white->PointIsntAvialabe();
	}
	return Point(-1, -1);
}