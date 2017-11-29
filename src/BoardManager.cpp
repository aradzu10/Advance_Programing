/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "BoardManager.h"
#include "RegularRules.h"
using namespace std;
#include <iostream>

BoardManager::BoardManager(int size) : board_size(size), amountOfBlack(0), amountOfWhite(0) {
	finder = new RegularRules();
	this->Init();
}
BoardManager::BoardManager(const BoardManager& b) : board_size(b.board_size), finder(NULL) {
	SetRule(b.finder->GetClone());
	Init(b.GetBoard());
//	SetCheckerAmount(b.amountOfBlack, b.amountOfWhite);
}
BoardManager::~BoardManager() {
	if (finder)
		delete finder;
}

void BoardManager::Init() {//board resize, Init
	board.resize(board_size, board_size);
	for (int r = 0; r < this->board_size; r++) {
		for (int c = 0; c < this->board_size; c++) {
			board[r][c] = Nothing;
		}
	}
	int mid = (this->board_size / 2) - 1;
	this->board[mid][mid] = White;
	this->board[mid + 1][mid] = Black;
	this->board[mid][mid + 1] = Black;
	this->board[mid + 1][mid + 1] = White;
	amountOfBlack = 2;
	amountOfWhite = 2;
}
void BoardManager::Init(const Matrix<Checker>& existBoard) {
	amountOfWhite = 0;
	amountOfBlack = 0;
	board.resize(board_size, board_size);
	for (int r = 0; r < this->board_size; r++) {
		for (int c = 0; c < this->board_size; c++) {
			board[r][c] = existBoard[r][c];
			if (board[r][c] == Black) {
				amountOfBlack++;
			} else if (board[r][c] == White) {
				amountOfWhite++;
			}
		}
	}
}
void BoardManager::SetRule(AvailableFinder* finder_) {
	if (finder)
		delete finder;
	finder = finder_;
}
void BoardManager::ResizeAndInit(int newSize) {
	this->board_size = newSize;
	this->Init();
}
void BoardManager::SetCheckerAmount(int blackAmount, int whiteAmount) {
	amountOfBlack = blackAmount;
	amountOfWhite = whiteAmount;
}

bool BoardManager::IsAvailable(int row, int colum, Checker available_to_check) {
	if ((row < 0 || row >= board_size) || (colum < 0 || colum >= board_size)) {
		return false;
	}
	if (board[row][colum] == available_to_check || board[row][colum] == AvailableBoth) {
		return true;
	}
	return false;
}
void BoardManager::FindAllAvailable() {
	finder->FindAllAvailable(board, board_size);
}
void BoardManager::AddToSum(Checker checker, int amount) {
	if (checker == Black) {
		amountOfBlack += amount;
	}
	if (checker == White) {
		amountOfWhite += amount;
	}
}

bool BoardManager::DoTurn(int row, int col, Checker to_put)
{
	Checker check_available = GetAvailableChecker(to_put);
	Checker to_turn_around = GetOppsiteChecker(to_put);

	if (!IsAvailable(row, col, check_available)) {
		return false;
	}

	this->board[row][col] = to_put;
	AddToSum(to_put, 1);

	bool found_checker = false;
	for (int r = row + 1; r < board_size; r++) {
		if (board[r][col] != to_turn_around) {
			if (found_checker && board[r][col] == to_put) {
				for (int i = row + 1; i < r; i++) {
					board[i][col] = to_put;
					AddToSum(to_put, 1);
					AddToSum(to_turn_around, -1);
				}
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	for (int r = row - 1; r >= 0; r--) {
		if (board[r][col] != to_turn_around) {
			if (found_checker && board[r][col] == to_put) {
				for (int i = row - 1; i > r; i--) {
					board[i][col] = to_put;
					AddToSum(to_put, 1);
					AddToSum(to_turn_around, -1);
				}
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	for (int c = col + 1; c < board_size; c++) {
		if (board[row][c] != to_turn_around) {
			if (found_checker && board[row][c] == to_put) {
				for (int i = col + 1; i < c; i++) {
					board[row][i] = to_put;
					AddToSum(to_put, 1);
					AddToSum(to_turn_around, -1);
				}
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	for (int c = col - 1; c >= 0; c--) {
		if (board[row][c] != to_turn_around) {
			if (found_checker && board[row][c] == to_put) {
				for (int i = col - 1; i > c; i--) {
					board[row][i] = to_put;
					AddToSum(to_put, 1);
					AddToSum(to_turn_around, -1);
				}
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	int lim = ((board_size - row) < (board_size - col)) ?
		(board_size - row) : (board_size - col);
	for (int i = 1; i < lim; i++) {
		if (board[row + i][col + i] != to_turn_around) {
			if (found_checker && board[row + i][col + i] == to_put) {
				for (int j = 1; j < i; j++) {
					board[row + j][col + j] = to_put;
					AddToSum(to_put, 1);
					AddToSum(to_turn_around, -1);
				}
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	lim = (row < col) ? row + 1 : col + 1;
	for (int i = 1; i < lim; i++) {
		if (board[row - i][col - i] != to_turn_around) {
			if (found_checker && board[row - i][col - i] == to_put) {
				for (int j = 1; j < i; j++) {
					board[row - j][col - j] = to_put;
					AddToSum(to_put, 1);
					AddToSum(to_turn_around, -1);
				}
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	lim = (row + 1 < (board_size - col)) ? row + 1 : (board_size - col);
	for (int i = 1; i < lim; i++) {
		if (board[row - i][col + i] != to_turn_around) {
			if (found_checker && board[row - i][col + i] == to_put) {
				for (int j = 1; j < i; j++) {
					board[row - j][col + j] = to_put;
					AddToSum(to_put, 1);
					AddToSum(to_turn_around, -1);
				}
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	lim = ((board_size - row) < col + 1) ? (board_size - row) : col + 1;
	for (int i = 1; i < lim; i++) {
		if (board[row + i][col - i] != to_turn_around) {
			if (found_checker && board[row + i][col - i] == to_put) {
				for (int j = 1; j < i; j++) {
					board[row + j][col - j] = to_put;
					AddToSum(to_put, 1);
					AddToSum(to_turn_around, -1);
				}
			}
			break;
		}
		found_checker = true;
	}

	return true;
}

bool BoardManager::CheckPlayerAvailable(Checker color) const {
	Checker available = GetAvailableChecker(color);

	for (int r = 0; r < this->board_size; r++) {
		for (int c = 0; c < this->board_size; c++) {
			if (this->board[r][c] == available || this->board[r][c] == AvailableBoth) {
				return true;
			}
		}
	}

	return false;
}
bool BoardManager::CheckIfGameEnded() {
	for (int r = 0; r < this->board_size; r++) {
		for (int c = 0; c < this->board_size; c++) {
			if (this->board[r][c] == AvailableB || this->board[r][c] == AvailableW ||
				this->board[r][c] == AvailableBoth) {
				return false;
			}
		}
	}

	return true;
}
Checker BoardManager::ReturnWinner() {
	if (amountOfBlack < amountOfWhite) {
		return White;
	} else if (amountOfBlack > amountOfWhite) {
		return Black;
	}
	return Nothing;
}

int BoardManager::GetSize() const {
	return board_size;
}
int BoardManager::GetAmountOfBlack() const {
	return amountOfBlack;
}
int BoardManager::GetAmountOfWhite() const {
	return amountOfWhite;
}
const Matrix<Checker>& BoardManager::GetBoard() const {
	return board;
}