/*
Name: Arad Zulti
ID: 315240564
*/

#ifndef GAME_MANAGER_
#define GAME_MANAGER_

#include "BoardManager.h"
#include "Checker.h"
#include "Player.h"
#include "Graphic.h"
#include "Point.h"

class GameManager
{
public:
	GameManager(BoardManager& board_);
	~GameManager();
	//change default settings - printer, players
	void SetPrinter(Graphic* printer_);
	void SetPlayers(Player* white_, Player* black_);
	//play game
	void StartGame();
private:
	//get point from player
	Point GetPointFromPlayer(Checker color);
	//get point from player with error message
	Point GetPointFromPlayerAgain(Checker color);
private:
	//members
	BoardManager& board;
	Player* white;
	Player* black;
	Graphic* printer;
};
#endif // !GAME_MANAGER_