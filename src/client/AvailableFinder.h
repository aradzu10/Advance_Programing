/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef AVAILABLE_FINDER_
#define AVAILABLE_FINDER_

#include "Matrix.h"
#include "Checker.h"

class AvailableFinder
{
public:
	AvailableFinder();
	virtual ~AvailableFinder();
	//find all available - do nothing, childs will
	virtual void FindAllAvailable(Matrix<Checker>& board, int board_size);
	//clone myself
	virtual AvailableFinder* GetClone();
};
#endif // !AVAILABLE_FINDER_