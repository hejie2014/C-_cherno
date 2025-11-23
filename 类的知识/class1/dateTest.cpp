#include <iostream>
#include "date.h"

using namespace std;


int main()
{
	Date today; // 默认构造函数，初始化为当前日期


	cout << "Today is " << today << ", " << today.day_of_week_str() << '-'<<today.day_of_week() << endl;
	cout << "Yesterday is " << today.preceding_day() << ", " << today.preceding_day().day_of_week() << endl;
	cout << "前天是： " << today.preceding_day().preceding_day() << ", " << today.preceding_day().day_of_week();
}