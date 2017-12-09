/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "Checker.h"

Checker GetOppositeChecker(Checker checker) {
	if (checker == Black) {
		return White;
	}
	if (checker == White) {
		return Black;
	}
	return Nothing;
}

Checker GetAvailableChecker(Checker checker) {
	if (checker == Black) {
		return AvailableB;
	}
	if (checker == White) {
		return AvailableW;
	}
	return Nothing;
}