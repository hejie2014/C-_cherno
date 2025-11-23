#include <iostream>

#include "accounting.h"

using namespace std;

// 构造函数
Accounting::Accounting(const string& name, long amnt, int y, int m, int d)
	: full_name(name), crnt_asset(amnt), birth(y, m, d)
{
}

// 设置信息的函数
void Accounting::setName(const std::string& name)  //设置姓名
{
	full_name = name;
}
void Accounting::setEarn(long amnt) //设置收入
{
	crnt_asset += amnt;
}
void Accounting::setSpend(long amnt)  //设置支出
{
	crnt_asset -= amnt;
}
void Accounting::setBirth(const Date& bd)  //设置生日
{
	birth = bd;
}