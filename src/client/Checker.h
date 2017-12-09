/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef CHECKER_
#define CHECKER_
//enum of board
enum Checker {
	Nothing = 0, Black, White, AvailableB, AvailableW, AvailableBoth
};
//get opposite color of checker
Checker GetOppositeChecker(Checker checker);
//get match available checker by color
Checker GetAvailableChecker(Checker checker);
#endif // !CHECKER_