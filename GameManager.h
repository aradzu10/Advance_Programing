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
	GameManager(int size_, BoardManager& board_);
	~GameManager();
	//change default settings - printer, players
	void SetPrinter(Graphic* printer_);
	void SetPlayers(Player* white_, Player* black_);
	//play game
	void StartGame();
private:
	//get opposite color - ex. get black return white
	Checker GetOppositeColor(Checker color);
	//get point from player
	Point GetPointFromPlayer(Checker color);
	//get point from player with error message
	Point GetPointFromPlayerAgain(Checker color);
	//
	Checker GetMatchAvailable(Checker color);
private:
	//members
	int board_size;
	BoardManager& board;
	Player* white;
	Player* black;
	Graphic* printer;
};
#endif // !GAME_MANAGER_