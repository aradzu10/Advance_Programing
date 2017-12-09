/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "ConsolePrinter.h"
#include <iostream>

using namespace std;


ConsolePrinter::ConsolePrinter() {
}


ConsolePrinter::~ConsolePrinter() {
}

void ConsolePrinter::PrintTurnOf(Checker player) const {
	cout << "It's the turn of player " << ReturnLetterToPrint(player) << ": " << endl;
}

void ConsolePrinter::PrintBoard(const Matrix<Checker>& board, int size) const {
	cout << "current board: " << endl << " |";
	int counter = 2;
	for (int i = 0; i < size; i++) {
		cout << " " << i + 1 << " |";
		counter += 4;
	}
	cout << endl;
	cout << string(counter, '-').c_str() << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "|";
		for (int j = 0; j < size; j++) {
			cout << " " << this->ReturnLetterToPrint(board[i][j]) << " |";
		}
		cout << endl;
		cout << string(counter, '-').c_str() << endl;
	}
}

void ConsolePrinter::PrintAvilable(const Matrix<Checker>& board, int size, Checker avilable_to_print) const {
	cout << "Your avilable options are: " << endl;
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (board[r][c] == avilable_to_print || board[r][c] == AvailableBoth) {
				cout << "(" << r+1 << "," << c+1 << ") ";
			}
		}
	}
	cout << endl;
}

void ConsolePrinter::PrintMessage(std::string s) const {
	cout << s.c_str() << endl;
}

void ConsolePrinter::PrintWinnerMessage(Checker winner) {
	cout << "The game ended!" << endl;
	cout << "The Winner is: " << ReturnLetterToPrint(winner) << " !" << endl;
}

char ConsolePrinter::ReturnLetterToPrint(Checker checker) const
{
	switch (checker) {
	case Black:
		return 'X';
	case White:
		return 'O';
	case AvailableB:
	case AvailableW:
	case AvailableBoth:
	case Nothing:
		return ' ';
	default:
		break;
	}
	return 0;
}

std::string ConsolePrinter::GetDataFromUser() {
	std::string s;
	getline(cin, s);
    return s;
}
