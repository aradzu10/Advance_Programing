/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef AI_PLAYER_
#define AI_PLAYER_

#include "Player.h"
#include "Point.h"
#include "Matrix.h"
#include "Checker.h"
#include "BoardManager.h"

class AIPlayer : public Player {

public:
	AIPlayer(Checker color, const BoardManager& board_, Graphic* graphic_);
	virtual ~AIPlayer();
	//get point from player
	virtual Point GetPointFromPlayer();
	//get point from player, with an error message
	virtual Point PointNotAvailable();
private:
	Point EmulateMyTurn(const BoardManager& bm);
	int EmulateOpponentTurn(const BoardManager& bm);
	int EmulateMyTurnOthers(const BoardManager& bm);
	int GetScoreOfBoard(const BoardManager& b, Checker checker);
private:
	const BoardManager& board;
};

#endif // !AI_PLAYER_