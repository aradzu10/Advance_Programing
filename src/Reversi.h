/*
Name: Arad Zulti
ID: 315240564
*/

#ifndef REVERSI_
#define REVERSI_

#include "GameManager.h"
#include "BoardManager.h"

class Reversi
{
public:
	Reversi(int size);
	~Reversi();
	//start game
	void StartGame();
private:
	//if you want to change the setting, like other players then the def, change here
	void ChangeSettings();
private:
	//members
	int board_size;
	GameManager game;
	BoardManager board;
};

#endif // !REVERSI_