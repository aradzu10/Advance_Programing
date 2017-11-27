/*
Name: Arad Zulti
ID: 315240564
*/

#include "RegularRules.h"
#include "BoardManager.h"

RegularRules::RegularRules() {
}

RegularRules::~RegularRules() {
}

void RegularRules::FindAllAvailable(Matrix<Checker>& board, int board_size) {
	DeleteAllAvailable(board, board_size);
	FindBlackAvailable(board, board_size);
	FindWhiteAvailable(board, board_size);
}

AvailableFinder * RegularRules::GetClone() {
	return new RegularRules();
}

void RegularRules::DeleteAllAvailable(Matrix<Checker>& board, int board_size) {
	for (int r = 0; r < board_size; r++) {
		for (int c = 0; c < board_size; c++) {
			switch (board[r][c]) {
			case Black:
			case White:
			case Nothing:
				break;
			case AvailableB:
			case AvailableW:
			case AvailableBoth:
				board[r][c] = Nothing;
				break;
			default:
				break;
			}
		}
	}
}
void RegularRules::FindBlackAvailable(Matrix<Checker>& board, int board_size) {
	for (int r = 0; r < board_size; r++) {
		for (int c = 0; c < board_size; c++) {
			Checker checker = board[r][c];
			if (checker == Black || checker == White) {
				continue;
			}
			if (CheckIfAvilable(board,board_size, r, c, Black, White) == true) {
				if (board[r][c] == AvailableW) {
					board[r][c] = AvailableBoth;
				}
				else {
					board[r][c] = AvailableB;
				}
			}
		}
	}
}
void RegularRules::FindWhiteAvailable(Matrix<Checker>& board, int board_size) {
	for (int r = 0; r < board_size; r++) {
		for (int c = 0; c < board_size; c++) {
			Checker checker = board[r][c];
			if (checker == Black || checker == White) {
				continue;
			}
			if (CheckIfAvilable(board, board_size, r, c, White, Black) == true) {
				if (board[r][c] == AvailableB) {
					board[r][c] = AvailableBoth;
				}
				else {
					board[r][c] = AvailableW;
				}
			}
		}
	}
}
bool RegularRules::CheckIfAvilable(Matrix<Checker>& board, int board_size, int row, int col, Checker current_checker, Checker checker_to_find) const {
	bool found_checker = false;
	for (int r = row + 1; r < board_size; r++) {
		if (board[r][col] != checker_to_find) {
			if (found_checker && board[r][col] == current_checker) {
				return true;
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	for (int r = row - 1; r >= 0; r--) {
		if (board[r][col] != checker_to_find) {
			if (found_checker && board[r][col] == current_checker) {
				return true;
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	for (int c = col + 1; c < board_size; c++) {
		if (board[row][c] != checker_to_find) {
			if (found_checker && board[row][c] == current_checker) {
				return true;
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	for (int c = col - 1; c >= 0; c--) {
		if (board[row][c] != checker_to_find) {
			if (found_checker && board[row][c] == current_checker) {
				return true;
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	int lim = ((board_size - row) < (board_size - col)) ?
		(board_size - row) : (board_size - col);
	for (int i = 1; i < lim; i++) {
		if (board[row + i][col + i] != checker_to_find) {
			if (found_checker && board[row + i][col + i] == current_checker) {
				return true;
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	lim = (row < col) ? row : col;
	for (int i = 1; i < lim; i++) {
		if (board[row - i][col - i] != checker_to_find) {
			if (found_checker && board[row - i][col - i] == current_checker) {
				return true;
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	lim = (row < (board_size - col)) ? row : (board_size - col);
	for (int i = 1; i < lim; i++) {
		if (board[row - i][col + i] != checker_to_find) {
			if (found_checker && board[row - i][col + i] == current_checker) {
				return true;
			}
			break;
		}
		found_checker = true;
	}

	found_checker = false;
	lim = ((board_size - row) < col) ? (board_size - row) : col;
	for (int i = 1; i < lim; i++) {
		if (board[row + i][col - i] != checker_to_find) {
			if (found_checker && board[row + i][col - i] == current_checker) {
				return true;
			}
			break;
		}
		found_checker = true;
	}

	return false;
}