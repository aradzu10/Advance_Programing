/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "AIPlayer.h"
#include <sstream>

using namespace std;

AIPlayer::AIPlayer(Checker color, const BoardManager& board_, Graphic* graphic_) :
		Player(color, graphic_), board(board_) {
}

AIPlayer::~AIPlayer() {
}

Point AIPlayer::GetPointFromPlayer() {
	Point point = EmulateMyTurn(board);
	
	stringstream ss;
	ss << "AI choose: (" << point.getRow() + 1 << ", " << point.getCol() + 1 << ")";
	graphic->PrintMessage(ss.str());
	return point;
}

Point AIPlayer::PointNotAvailable() {
	return GetPointFromPlayer();
}

Point AIPlayer::EmulateMyTurn(const BoardManager& bm) {
	int minScore = bm.GetSize();
	int tmpScore = 0;
	minScore *= minScore;
	minScore++;
	int minRow = -1, minCol = -1;
	const Matrix<Checker>& b = bm.GetBoard();
	for (int r = 0; r < bm.GetSize(); r++) {
		for (int c = 0; c < bm.GetSize(); c++) {
			if (b[r][c] == GetAvailableChecker(player_color) || b[r][c] == AvailableBoth) {
				BoardManager tmpBM(bm);
				tmpBM.DoTurn(r, c, player_color);
				tmpScore = EmulateOpponentTurn(tmpBM);
				if (tmpScore <= minScore) {
					minScore = tmpScore;
					minRow = r;
					minCol = c;
				}
			}
		}
	}
	return Point(minRow, minCol);
}

int AIPlayer::EmulateOpponentTurn(const BoardManager& bm) {
	int maxScore = bm.GetSize();
	maxScore *= -1*maxScore;
	maxScore--;
	const Matrix<Checker>& b = bm.GetBoard();
	if (!bm.CheckPlayerAvailable(GetOppositeChecker(player_color))) {
		return GetScoreOfBoard(bm, GetOppositeChecker(player_color));
	}
	for (int r = 0; r < bm.GetSize(); r++) {
		for (int c = 0; c < bm.GetSize(); c++) {
			if (b[r][c] == GetAvailableChecker(GetOppositeChecker(player_color)) || b[r][c] == AvailableBoth) {
				BoardManager tmpBM(bm);
				tmpBM.DoTurn(r, c, player_color);
//				int tmpScore = EmulateMyTurnOthers(tmpBM);
				int tmpScore = GetScoreOfBoard(tmpBM, GetOppositeChecker(player_color));
				if (tmpScore >= maxScore) {
					maxScore = tmpScore;
				}
			}
		}
	}
	return maxScore;
}

int AIPlayer::EmulateMyTurnOthers(const BoardManager& bm) {
	int minScore = bm.GetSize();
	int tmpScore = 0;
	minScore *= minScore;
	minScore++;
	const Matrix<Checker>& b = bm.GetBoard();
	for (int r = 0; r < bm.GetSize(); r++) {
		for (int c = 0; c < bm.GetSize(); c++) {
			if (b[r][c] == GetAvailableChecker(player_color) || b[r][c] == AvailableBoth) {
				BoardManager tmpBM(bm);
				tmpBM.DoTurn(r, c, player_color);
				tmpScore = EmulateOpponentTurn(tmpBM);
				if (tmpScore <= minScore) {
					minScore = tmpScore;
				}
			}
		}
	}
	return minScore;
}

int AIPlayer::GetScoreOfBoard(const BoardManager& bm, Checker checker) {
	if (checker == Black) {
		return bm.GetAmountOfBlack() - bm.GetAmountOfWhite();
	}
	if (checker == White) {
		return bm.GetAmountOfWhite() - bm.GetAmountOfBlack();
	}
	return 0;
}