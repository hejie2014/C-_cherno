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
	operator unsigned int() const
	{
		return count;
	}
	//重载输出运算符
	// 判断计数是否不相等
	bool operator!= (const Counter& other) const
	{
		return this->count != other.count;
	}
	// 判断计数是否相等
	bool operator== (const Counter& other) const
	{
		return this->count == other.count;
	}
	// 判断计数是否为零
	bool operator!() const
	{
		return this->count == 0;
	}

	Counter& operator++() // 前置++
	{
		increment();
		// if(count < std::numeric_limits<unsigned int>::max()) count++;

		return *this;
	}
	Counter operator++(int) // 后置++
	{
		Counter temp = *this;
		++(*this);
		// if(count < std::numeric_limits<unsigned int>::max()) count++;
		return temp;
	}
	Counter& operator--() // 前置--
	{
		decrement();
		// if(count > 0) count--;
		return *this;
	}
	Counter operator--(int) // 后置--
	{
		Counter temp = *this;
		--(*this);
		// if(count < std::numeric_limits<unsigned int>::max()) count++;
		return temp;
	}
	/*
	 unsigned x;
	 //获取计数值
	 Counter cnt;
	 x = unsigned(cnt);
	 x = cnt;
	 x = (unsigned)cnt;
	 X = static_cast<unsigned>(cnt);
	*/
	/*unsigned int getCount() const
	{
		return count;
	}*/
};
