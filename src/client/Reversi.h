/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef REVERSI_
#define REVERSI_

#include "GameManager.h"
#include "BoardManager.h"
#include "ServerLinker.h"

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
	void SetupLocalGameWithAIPlayer();
	void SetupLocalGameWithBothAIPlayer();
	void SetupRemoteGame();
	void ClientMenu(ServerLinker *link, Graphic *printer);

private:
	//members
	int board_size;
	GameManager game;
	BoardManager board;
};

#endif // !REVERSI_