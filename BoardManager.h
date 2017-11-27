/*
Name: Arad Zulti
ID: 315240564
*/

#ifndef BOARD_H_
#define BOARD_H_

#include "Matrix.h"
#include "Checker.h"

class AvailableFinder;

class BoardManager
{
public:
	BoardManager(int size);
	BoardManager(const BoardManager& b);
	~BoardManager();
	//Init a new board
	void Init();
	void Init(const Matrix<Checker>& existBoard);
	//change who is available
	void SetRule(AvailableFinder *finder_);
	//Change the size of the board and init a new board
	void ResizeAndInit(int newSize);
	void SetCheckerAmount(int blackAmount, int whiteAmount);
	//find all available - by finder member
	void FindAllAvailable();
	//get checker and put at place, then turn around which it need
	bool DoTurn(int row, int colum, Checker to_put);
	//check if player have available moves
	bool CheckPlayerAvailable(Checker color) const ;
	//check if both player have available moves
	bool CheckIfGameEnded();
	//return winner player
	Checker ReturnWinner();
	int GetSize() const;
	int GetAmountOfBlack() const;
	int GetAmountOfWhite() const;
	//return const board
	const Matrix<Checker>& GetBoard() const;
private:
	//check if checker is available to player
	bool IsAvailable(int row, int colum, Checker available_to_check);
	void AddToSum(Checker checker, int amount);
private:
	//members
	int board_size;
	int amountOfBlack, amountOfWhite;
	Matrix<Checker> board;
	AvailableFinder* finder;

};
#endif