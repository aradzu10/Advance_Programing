/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
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
	bool operator==(const Point& point) const;
private:
	//members
	int r;
	int c;
};
#endif // !POINT_H_