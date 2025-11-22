#pragma once


#include <iostream>
#include <string>

class Date {
private:
	int m_year;
	int m_month;
	int m_day;

public:
	Date();
	Date(int year, int month = 1, int day = 1);

	int getYear() const { return m_year; }
	int getMonth() const { return m_month; }
	int getDay() const { return m_day; }

	Date preceding_day() const;
	std::string to_string() const;
	int day_of_week() const;
	std::string day_of_week_str() const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);
std::istream& operator>>(std::istream& is, Date& date);
