/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "HumanPlayer.h"
#include <cstdio>

using namespace std;

HumanPlayer::HumanPlayer(Checker color, Graphic* graphic_) :
		Player(color, graphic_) {}

HumanPlayer::~HumanPlayer() {}

Point HumanPlayer::GetPointFromPlayer() {
	int row = 0, col = 0;
	graphic->PrintMessage("Please enter location to put disc (format: \"row colum\"): ");
	std::string line = graphic->GetDataFromUser();
	sscanf(line.c_str(), "%d %d", &row, &col);
	return Point(row - 1, col - 1);
}

Point HumanPlayer::PointNotAvailable() {
	int row = 0, col = 0;
	graphic->PrintMessage("You enterd incorrect location...");
	graphic->PrintMessage("Please enter new location to put disc (format: \"row column\"): ");
	std::string line = graphic->GetDataFromUser();
	sscanf(line.c_str(), "%d %d", &row, &col);
	return Point(row - 1, col - 1);
}