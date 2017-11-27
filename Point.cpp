/*
Name: Arad Zulti
ID: 315240564
*/

#include "Point.h"

Point::Point(int row, int col): r(row), c(col) {
}

Point::~Point() {
}

int Point::getRow()
{
	return this->r;
}

int Point::getCol()
{
	return this->c;
}
