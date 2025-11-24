#include <iostream>
#include "counter.h"

using namespace std;


int main()
{
	int number;
	Counter x;
	Counter y;
	cout << "当前的计数值： " << static_cast<unsigned int>(x) << endl;
	cout << "增加计数的次数： ";
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		cout << ++x << ' ' << y++ << endl;
	}
	cout << "x=" << x << ", y=" << y << endl;
	cout << "减少计数的次数： ";
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		cout << --x << ' ' << y-- << endl;
	}
	cout << "x=" << x << ", y=" << y << endl;
}

//当前的计数值： 0
//增加计数的次数： 4
//1 0
//2 1
//3 2
//4 3
//x = 4, y = 4
//减少计数的次数： 3
//3 4
//2 3
//1 2
//x = 1, y = 1

//int main()
//{
//	int number;
//	Counter x;
//	cout << "当前的计数值： " << x.operator unsigned int() << endl;
//	// x.operator unsigned int()
//	cout << "增加计数的次数： ";
//	cin >> number;
//	for (int i = 0; i < number; i++)
//	{
//		x.increment();
//		cout << x << endl;
//	}
//	cout << "减少计数的次数： ";
//	cin >> number;
//	for (int i = 0; i < number; i++)
//	{
//		x.decrement();
//		cout << x<< endl;
//	}
//}