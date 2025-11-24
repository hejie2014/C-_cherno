#include <iostream>
#include "circle.h"
#include "point2D.h"

using std::cout;
using std::endl;

int main() {
	// s_counter为私有成员变量，无法在类的外部进行访问，使用提供的外部接口函数getMaxId()来获取最大ID值
//	cout << "Point2D ID_NO: " << Point2D::s_counter << endl;
	cout << "Max Point2D ID: " << Point2D::getMaxId() << endl;
	Point2D origin(0, 0);
	Circle c1(Point2D(3, 5), 7);
	Circle c2(Point2D(), 8);
	Circle c3(Point2D(1), 8);
	Circle c4(origin, 8);

	// 测试point2D的计数
	//cout << "Point2D ID_NO: " << Point2D::s_counter << endl;
	cout << "Point2D c1_ID_NO: " << c1.getCenter().getID() << endl;
	cout << "Point2D c2_ID_NO: " << c2.getCenter().getID() << endl;
	cout << "Point2D c3_ID_NO: " << c3.getCenter().getID() << endl;
	cout << "Point2D c4_ID_NO: " << c4.getCenter().getID() << endl;
	cout << "Max Point2D ID: " << Point2D::getMaxId() << endl;


	cout << "c1 = "; c1.print();  cout << endl;
	cout << "c2 = "; c2.print();  cout << endl;
	cout << "c3 = "; c3.print();  cout << endl;
	cout << "c4 = "; c4.print();  cout << endl;
	cout << "===================" << endl;
	// 使用重载的 << 运算符
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	cout << "c4 = " << c4 << endl;
}