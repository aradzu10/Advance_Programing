/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef CHECKER_
#define CHECKER_

enum Checker {
	Nothing = 0, Black, White, AvailableB, AvailableW, AvailableBoth
};

Checker GetOppsiteChecker(Checker checker);

Checker GetAvailableChecker(Checker checker);
#endif // !CHECKER_