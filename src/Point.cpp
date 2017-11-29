/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
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

bool Point::operator==(const Point& point) const {
	return (c == point.c) && (r == point.r);
}
