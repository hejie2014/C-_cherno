#ifndef ___ACCOUNTING
#define ___ACCOUNTING

#include <string>
#include "date.h"

class Accounting {
private:
	std::string full_name;  // 姓名
	long crnt_asset;  //资产
	Date birth;   // 生日

public:
	// 构造函数
	Accounting(const std::string& name, long amnt, const Date& bd);
	// 获取信息的函数，注意使用const修饰，不修改成员变量
	std::string getName() const { return full_name; }
	long getAsset() const { return crnt_asset; }
	Date getBirthday() const { return birth; }
	// 设置信息的函数
	// cosnt--防止“原件”被修改（安全性）允许传入临时对象（通用性）—— 这一点非常重要！
	//C++ 规定：非 const 引用（Date & ）不能指向临时对象（R - value）。
	void setName(const std::string& name);  //设置姓名
	void setEarn(long amnt); //设置收入
	void setSpend(long amnt);  //设置支出
	void setBirth(const Date& bd);  //设置生日

};




#endif
