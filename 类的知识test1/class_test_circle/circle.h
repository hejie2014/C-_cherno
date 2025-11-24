#pragma once
//#include <sstream>
#include "point2D.h"

class Circle {
private:
	Point2D center;
	int radius;

public:
	Circle(const Point2D& c, int r)
		: center(c), radius(r) {
	}
	Point2D getCenter() const {
		return center;
	}
	int getRadius() const {
		return radius;
	}
	void print() const {
		std::cout << "Circle(Center: ";
		center.print();
		std::cout << ", Radius: " << radius << ")\n";
	}
	// 修正：加上 friend 关键字
 // 这告诉编译器：虽然我写在类里面，但我不是成员函数，我是外部函数，
 // 但我有权限访问类的私有成员（如果有需要的话）。
	//friend std::ostream& operator<<(std::ostream& os, const Circle& circle)
	//{
	//	os << "Circle(Center: (" << circle.getCenter().getX() << ", " << circle.getCenter().getY() << "), Radius: " << circle.getRadius() << ")";
	//	return os;
	//}
	/*std::ostream& operator<<(std::ostream& os, const Circle& circle)
	{

	}*/
};

std::ostream& operator<<(std::ostream& os, const Circle& c)
{

	os << "Circle(Center: " << c.getCenter() << ", Radius: " << c.getRadius() << ")";
	return os;
}

/*
class Circle {
	// ... 类的其他部分 ...
}; // 类结束

// 在类外面定义
inline std::ostream& operator<<(std::ostream& os, const Circle& circle) {
	os << "Circle(Center: (" << circle.getCenter().getX() << ", "
	   << circle.getCenter().getY() << "), Radius: " << circle.getRadius() << ")";
	return os;
}

*/