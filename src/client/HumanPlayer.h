/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef CONSOLE_PLAYER_
#define CONSOLE_PLAYER_

#include "Player.h"
#include "Point.h"

class ConsolePlayer : public Player {

public:
	ConsolePlayer(Checker color, const BoardManager& board_, Graphic* graphic_);
	virtual ~ConsolePlayer();
	//get point from player
	virtual Point GetPointFromPlayer();
	//get point from player, with an error message
	virtual Point PointIsntAvialabe();
};
#endif