#include <ctime>
#include <iostream>

int main() {

	time_t current = time(nullptr);
	struct tm local_time;
	localtime_s(&local_time , &current);
	const char* week_days[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };

	std::cout << "当前的日期时间是： "
		<< local_time.tm_year + 1900 << "年"
		<< local_time.tm_mon + 1 << "月"
		<< local_time.tm_mday << "日 ("
		<< week_days[local_time.tm_wday] << ") "
		<< local_time.tm_hour << "时"
		<< local_time.tm_min << "分"
		<< local_time.tm_sec << "秒" << std::endl;
	/*std::cout << "当前的日期时间是： "
		<< local_time->tm_year + 1900 << "年"
		<< local_time->tm_mon + 1 << "月"
		<< local_time->tm_mday << "日 ("
		<< week_days[local_time->tm_wday] << ") "
		<< local_time->tm_hour << "时"
		<< local_time->tm_min << "分"
		<< local_time->tm_sec << "秒" << std::endl;*/
}
//'localtime': This function or variable may be unsafe. Consider using localtime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.

/*
struct tm
{
	int tm_sec;   // seconds after the minute - [0, 60] including leap second
	int tm_min;   // minutes after the hour - [0, 59]
	int tm_hour;  // hours since midnight - [0, 23]
	int tm_mday;  // day of the month - [1, 31]
	int tm_mon;   // months since January - [0, 11]
	int tm_year;  // years since 1900
	int tm_wday;  // days since Sunday - [0, 6]
	int tm_yday;  // days since January 1 - [0, 365]
	int tm_isdst; // daylight savings time flag
};

*/