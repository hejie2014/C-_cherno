#include <iostream>

using namespace std;

class Test {
public:
	Test()
	{
		cout << "默认构造函数初始化： Test()\n";
	}
	Test(const Test& t)
	{
		cout << "拷贝构造函数初始化： Test(const Test& t)\n";
	}
	Test& operator=(const Test& t)
	{
		cout << "代入运算符： Test = Test\n";
		return *this;
	}
};
// 值传递， 会调用拷贝构造函数
void value(Test a)
{
}
// 引用传递， 避免拷贝构造函数调用
void reference(Test& a)
{
}


//int main()
//{
//	Test x;
//	Test y = x; // 调用拷贝构造函数
//	Test z(x); // 调用拷贝构造函数
//	y = x; // 调用代入运算符
//	value(x); // 调用拷贝构造函数
//	reference(x); // 不调用拷贝构造函数
//}
/*
默认构造函数初始化： Test()
拷贝构造函数初始化： Test(const Test& t)
拷贝构造函数初始化： Test(const Test& t)
代入运算符： Test = Test
拷贝构造函数初始化： Test(const Test& t)
*/