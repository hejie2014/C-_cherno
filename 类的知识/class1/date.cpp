#include <ctime>
#include <iostream>
#include <sstream>
#include "date.h"

using namespace std;

// 默认的构造函数，初始化为当前日期
Date::Date() {
	time_t current = time(NULL);
	struct tm* nowTime = localtime(&current);

	m_year = nowTime->tm_year + 1900;
	m_month = nowTime->tm_mon + 1;
	m_day = nowTime->tm_mday;

}
/*
// 或者解决方案2：使用this指针
// Date::Date(int year, int month, int day) {
//     this->m_year = year;
//     this->m_month = month;
//     this->m_day = day;
// }
// 或者解决方案3：参数使用不同名称
// Date::Date(int y, int m, int d) {
//     m_year = y;
//     m_month = m;
//     m_day = d;
// }
*/
Date::Date(int year, int month, int day)
	: m_year(year), m_month(month), m_day(day)
{
}

Date Date::preceding_day() const {
	// 使用拷贝构造函数创建一个当前日期的副本
	Date prevDate = *this; // *this表示当前对象的引用

	if (prevDate.m_day > 1)
	{
		prevDate.m_day--;
	}
	else
	{
		if (--prevDate.m_month < 1)  
		{
			prevDate.m_year--;
			prevDate.m_month = 12;
		}
		static const int m_daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		prevDate.m_day = m_daysInMonth[prevDate.m_month - 1];
		//处理闰年的情况
		if (prevDate.m_month == 2 && ((prevDate.m_year % 4 == 0 && prevDate.m_year % 100 != 0) || (prevDate.m_year % 400 == 0)))
		{
			prevDate.m_day = 29;
		}
	}
	//prevDate.m_day--;

	//if (prevDate.m_day < 1) {
	//	prevDate.m_month--;
	//	if (prevDate.m_month < 1) {
	//		prevDate.m_year--;
	//		prevDate.m_month = 12;
	//	}
	//	static const int m_daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//	prevDate.m_day = m_daysInMonth[prevDate.m_month - 1];
	//	//处理闰年的情况
	//	if (prevDate.m_month == 2 && ((prevDate.m_year % 4 == 0 && prevDate.m_year % 100 != 0) || (prevDate.m_year % 400 == 0))) {
	//		prevDate.m_day = 29;
	//	}
	//}
	return prevDate;
}

string Date::to_string() const {
	ostringstream oss;
	oss << m_year << "-" << (m_month < 10 ? "0" : "") << m_month << "-" << (m_day < 10 ? "0" : "") << m_day;
	return oss.str();
}

string Date::day_of_week_str() const {
	// 一个数组，数据类型是string，包含7个元素，分别表示星期六到星期五
	static const string days[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	int dow = day_of_week();
	return days[dow];
}


int Date::day_of_week() const {
	int y = m_year;
	int m = m_month;
	// Zeller公式调整月份和年份(m == 1 || m==2)
	// 蔡勒公式要求 1月和2月必须被视为上一年的13月和14月。例如，2023年1月必须作为2022年13月输入
	if (m < 3) {
		m += 12;
		y--;
	}
	int k = y % 100;  // 年份的后两位 
	int j = y / 100; // 年份的前两位
	int f = m_day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;

	// (y + (y/4) - (y/100) + (y/400) + (13*m + 8)/5 + d) % 7; 星期日~星期六（0~6）
	return f % 7; // 0=Saturday, 1=Sunday, ..., 6=Friday
}


// 流操作符重载，用于输出Date对象
ostream& operator<<(ostream& os, const Date& date)
{
	os << date.to_string();
	return os;
}
// & 引用传递，避免不必要的拷贝，只是别名，直接使用date源对象
istream& operator>>(istream& is, Date& date)
{
	string dateStr;
	is >> dateStr;
	int year, month, day;
	char dash1, dash2; // 用于读取分隔符 '-'
	istringstream iss(dateStr);
	iss >> year >> dash1 >> month >> dash2 >> day;
	if (iss && dash1 == '-' && dash2 == '-') {
		date = Date(year, month, day);
	}
	else {
		is.setstate(ios::failbit); // 设置流的失败状态
	}
	return is;
}