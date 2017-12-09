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
	//constractor create AIPlayer
	AIPlayer(Checker color, const BoardManager& board_, Graphic* graphic_);
	virtual ~AIPlayer();
	//get point from player
	virtual Point GetPointFromPlayer();
	//get point from player, with an error message
	virtual Point PointNotAvailable();
private:
	//Emulate my turn - do every available move
	Point EmulateMyTurn(const BoardManager& bm);
	//Emulate oppentnent turn - do every available move
	int EmulateOpponentTurn(const BoardManager& bm);
	//not in use (emulate all the game)
	int EmulateMyTurnOthers(const BoardManager& bm);
	//get score for board - number of checkers of player minus number of checkers of opponent
	int GetScoreOfBoard(const BoardManager& b, Checker checker);
private:
	//members
	const BoardManager& board;
};

#endif // !AI_PLAYER_