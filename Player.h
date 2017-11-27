/*
Name: Arad Zulti
ID: 315240564
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Point.h"
#include "BoardManager.h"
#include "Graphic.h"
#include "Checker.h"

class Player
{
public:
	Player(Checker color, const BoardManager& board_, Graphic* graphic_);
	virtual ~Player();
	//get point from player - return false point, childs will change it
	virtual Point GetPointFromPlayer();
	virtual Point PointIsntAvialabe();
protected:
	//members
	Checker player_color;
	const BoardManager& board;
	Graphic* graphic;
};
#endif // !PLAYER_H_