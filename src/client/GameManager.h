/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
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
	//members
	BoardManager& board;
	Player* white;
	Player* black;
	Graphic* printer;
};
#endif // !GAME_MANAGER_