/*
Name: Arad Zulti
ID: 315240564
*/

#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
	Point(int row, int col);
	~Point();
	//gets
	int getRow();
	int getCol();
private:
	//members
	int r;
	int c;
};
#endif // !POINT_H_