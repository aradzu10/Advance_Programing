#include "Checker.h"

Checker GetOppsiteChecker(Checker checker) {
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