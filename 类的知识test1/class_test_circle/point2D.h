#pragma once
#include <iostream>


class Point2D {

private:
	int xp;
	int yp;
	int id_no;
	static int s_counter;

public:	
	Point2D(int x = 0, int y=0)
		:xp(x), yp(y), id_no(++s_counter)
	{}
	int getX() const { return xp; }
	int getY() const { return yp; }
	int getID() const { return id_no; }
	void print() const
	{
		std::cout << "Point2D(" << xp << ", " << yp << ")\n";
	}
	static int getMaxId() { return s_counter; }
};
// 静态成员变量初始化
int Point2D::s_counter = 0;

std::ostream& operator<<(std::ostream& os, const Point2D& p)
{
	return os << "(" << p.getX() << ", " << p.getY() << ")";
}