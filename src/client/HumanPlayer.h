/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef HUMAN_PLAYER_
#define HUMAN_PLAYER_

#include "Player.h"
#include "Point.h"

class HumanPlayer : public Player {

public:
	HumanPlayer(Checker color, const BoardManager& board_, Graphic* graphic_);
	virtual ~HumanPlayer();
	//get point from player
	virtual Point GetPointFromPlayer();
	//get point from player, with an error message
	virtual Point PointNotAvailable();
};

#endif