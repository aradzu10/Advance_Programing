/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "GameManager.h"
#include "HumanPlayer.h"
#include "ConsolePrinter.h"

GameManager::GameManager(BoardManager& board_) : board(board_) {
	printer = new ConsolePrinter();
	white = new HumanPlayer(White, board, printer);
	black = new HumanPlayer(Black, board, printer);
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
	Player *currentPlayer = black;
	Player *nextPlayer = white;
	Player *tmpP;
	while (true) {
		board.FindAllAvailable();
		printer->PrintBoard(board.GetBoard(), board.GetSize());
		currentPlayer->MyTurn();
		if (!board.CheckPlayerAvailable(currentPlayer->GetColor())) {
			currentPlayer->NoMove();
			if (board.CheckIfGameEnded()) {
				currentPlayer->GameEnded();
				if (board.ReturnWinner() == Nothing) {
					printer->PrintMessage("It's a tie!");
				} else {
					printer->PrintWinnerMessage(currentPlayer->GetColor());
				}
				break;
			}
			printer->PrintMessage("Turn go to next player");
			tmpP = currentPlayer;
			currentPlayer = nextPlayer;
			nextPlayer = tmpP;
			continue;
		}
		printer->PrintAvilable(board.GetBoard(), board.GetSize(), GetAvailableChecker(currentPlayer->GetColor()));
		Point tmp = currentPlayer->GetPointFromPlayer();
		while (!board.DoTurn(tmp.getRow(), tmp.getCol(), currentPlayer->GetColor())) {
			tmp = currentPlayer->PointNotAvailable();
		}
		currentPlayer->SuccessfulTurn(tmp);
		tmpP = currentPlayer;
		currentPlayer = nextPlayer;
		nextPlayer = tmpP;
	}
}