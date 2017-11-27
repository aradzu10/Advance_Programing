/*
Name: Arad Zulti
ID: 315240564
*/

#ifndef REGULAR_RULES_
#define REGULAR_RULES_

#include "AvailableFinder.h"
#include "Checker.h"

class RegularRules :
	public AvailableFinder
{
public:
	RegularRules();
	virtual ~RegularRules();
	//find all available
	virtual void FindAllAvailable(Matrix<Checker>& board, int board_size);
	virtual AvailableFinder* GetClone();

private:
	//delete all available
	void DeleteAllAvailable(Matrix<Checker>& board, int board_size);
	//find all black available
	void FindBlackAvailable(Matrix<Checker>& board, int board_size);
	//find all white available
	void FindWhiteAvailable(Matrix<Checker>& board, int board_size);
	//check if position is available
	bool CheckIfAvilable(Matrix<Checker>& board, int board_size, int row, int col, Checker current_checker, Checker checker_to_find) const;
};
#endif // !REGULAR_RULES_