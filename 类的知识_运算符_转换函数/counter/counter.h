#pragma once
#include <iostream>

#include <limits>

class Counter {
private:
	unsigned int count;
public:
	//构造函数
	Counter() : count(0) {}
	//增加计数
	void increment() {
		if (count < std::numeric_limits<unsigned int>::max())
			count++;
	}
	//减小计数
	void decrement()
	{
		if (count > 0)
			count--;
		else
			std::cout << "Counter cannot go below zero." << std::endl;
	}
	//获取计数值
	unsigned int getCount() const
	{
		return count;
	}
};
