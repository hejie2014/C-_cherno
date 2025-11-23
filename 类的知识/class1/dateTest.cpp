#include <iostream>
#include "date.h"
#include <sstream>

using namespace std;

int main()
{
    string s = "2125/12/18";
    istringstream iss(s);
    int y, m, d;
    char ch;

    iss >> y;
    cout << "读取年份: " << y << endl;

    iss >> ch;
    cout << "读取第一个字符: '" << ch << "'" << endl;

    iss >> m;
    cout << "读取月份: " << m << endl;

    iss >> ch;  // 这里会出错！
    cout << "读取第二个字符: '" << ch << "'" << endl;

    iss >> d;
    cout << "读取日期: " << d << endl;
	cout << y << " " << m << " " << d << endl;

}



//int main()
//{
//	const Date birthday(1963, 11, 18); // 默认构造函数，初始化为当前日期
//	Date day[3];
//	cout << "birthday = " << birthday << endl;
//	cout << "birthday的字符串的格式信息： " << birthday.to_string() << endl;
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "day[" << i << "] 的字符串的格式信息： " << day[i].to_string() << endl;
//	}
//	//cout << "Today is " << today << ", " << today.day_of_week_str() << '-'<<today.day_of_week() << endl;
//	//cout << "Yesterday is " << today.preceding_day() << ", " << today.preceding_day().day_of_week() << endl;
//	//cout << "前天是： " << today.preceding_day().preceding_day() << ", " << today.preceding_day().day_of_week();
//}