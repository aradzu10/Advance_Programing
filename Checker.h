#ifndef CHECKER_
#define CHECKER_

enum Checker {
	Nothing = 0, Black, White, AvailableB, AvailableW, AvailableBoth
};

Checker GetOppsiteChecker(Checker checker);

Checker GetAvailableChecker(Checker checker);
#endif // !CHECKER_

