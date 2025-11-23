#include <ctime>
#include <iostream>
#include <sstream>
#include "date.h"

using namespace std;

// 默认的构造函数，初始化为当前日期
Date::Date() {
	time_t current = time(NULL);
	struct tm nowTime; // 1. 在栈上分配一个具体的结构体，而不是指针

	//struct tm* nowTime = localtime(&current);
	localtime_s(&nowTime, &current);
	m_year = nowTime.tm_year + 1900;
	m_month = nowTime.tm_mon + 1;
	m_day = nowTime.tm_mday;
	/*m_year = nowTime->tm_year + 1900;
	m_month = nowTime->tm_mon + 1;
	m_day = nowTime->tm_mday;*/
	/*
	localtime 和 localtime_s 的区别在于谁负责提供内存（房子）：
localtime（旧版）：
	它自己内部有一个静态的房子（static struct tm）。
	它把数据写进去，然后把**钥匙（指针）**交给你。
	所以你定义 struct tm* p 去接这个钥匙是对的。
localtime_s（新版安全版）：
	它不负责提供房子。它要求你必须自己先盖好一个房子（在栈上分配内存）。
	然后你把房子的**地址（指针）**告诉它，它才会进去把数据填好。
	因为你只定义了 struct tm* nowTime 而没有初始化，这个指针指向的是随机的内存区域（也就是你没盖房子，只拿了个写着随机地址的门牌号），函数试图往这个随机地址写数据，程序就会崩溃（Access Violation）或报错“使用了未初始化的局部变量”。
	*/
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
	//return  (y + (y / 4) - (y / 100) + (y / 400) + (13 * m + 8) / 5 + m_day) % 7;
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
	is >> dateStr; //首先从输入流中读取一段不含空格的字符串。例如用户输入 2023-11-22，整个字符串被读入 dateStr
	int year, month, day;
	char dash1, dash2; // 用于读取分隔符 '-'
	istringstream iss(dateStr);//它创建了一个“字符串流” iss，内容就是刚才读到的 dateStr
	//     这样做的好处是我们可以像操作 cin 一样操作这个字符串，从中提取数字和字符，而不影响主输入流 is 后面的内容。
	iss >> year >> dash1 >> month >> dash2 >> day;
	if (iss && dash1 == '-' && dash2 == '-') {
		date = Date(year, month, day);
	}
	else {
		is.setstate(ios::failbit); // 设置流的失败状态
	}
	return is;
}
/*
. 输入处理方式不同
方式一（字符串方式）：
is >> dateStr 读取直到遇到空格、制表符或换行
然后只在dateStr内部解析，不影响主输入流后续内容
方式二（直接方式）：
直接从主输入流读取，会影响后续的输入操作
优点：
更好的隔离性：解析错误不会污染主输入流
更清晰的错误处理：可以精确控制错误状态
调试友好：可以查看完整的输入字符串
灵活性：可以添加更复杂的解析逻辑
*/