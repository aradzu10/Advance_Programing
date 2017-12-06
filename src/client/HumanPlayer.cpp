/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "HumanPlayer.h"
#include <iostream>

using namespace std;

ConsolePlayer::ConsolePlayer(Checker color, const BoardManager& board_, Graphic* graphic_) :
		Player(color, board_, graphic_) {}

ConsolePlayer::~ConsolePlayer() {}

Point ConsolePlayer::GetPointFromPlayer() {
	int row, col;
	graphic->PrintMessage("Please enter location to put disc (format: \"row colum\"): ");
	cin >> row;
	cin >> col;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000,'\n');
		return Point(-1, 0);
	}
	return Point(row - 1, col - 1);
}

Point ConsolePlayer::PointNotAvailable() {
	int row, col;
	graphic->PrintMessage("You enterd incorrect location...");
	graphic->PrintMessage("Please enter new location to put disc (format: \"row column\"): ");
	cin >> row;
	cin >> col; 
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		return Point(-1, 0);
	}
	return Point(row - 1, col - 1);
}