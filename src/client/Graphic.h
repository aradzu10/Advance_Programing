/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef GRAPHIC_
#define GRAPHIC_

#include "Checker.h"
#include "Matrix.h"
#include <iostream>

class Graphic
{
public:
	Graphic();
	virtual ~Graphic();
	//print who turn is that
	virtual void PrintTurnOf(Checker player) const;
	//print board
	virtual void PrintBoard(const Matrix<Checker>& board, int size) const;
	//print available in board
	virtual void PrintAvilable(const Matrix<Checker>& board, int size, Checker avilable_to_print) const;
	//print recived messgae
	virtual void PrintMessage(std::string s) const;
	//print winner messgae
	virtual void PrintWinnerMessage(Checker winner);
};
#endif