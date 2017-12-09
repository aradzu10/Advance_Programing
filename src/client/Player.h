/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
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
	Player();
	Player(Checker color, Graphic* graphic_);
	virtual ~Player();
	virtual Checker GetColor();
	//get point from player - return false point, childs will change it
	virtual Point GetPointFromPlayer();
	virtual Point PointNotAvailable();
	virtual void MyTurn();
	virtual void SuccessfulTurn(Point point);
	virtual void NoMove();
	virtual void GameEnded();

protected:
	//members
	Checker player_color;
	Graphic* graphic;
};
#endif // !PLAYER_H_