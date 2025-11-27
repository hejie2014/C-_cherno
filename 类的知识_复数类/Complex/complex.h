#pragma once
#include <iostream>


class Complex {
private:
	double re; // 实部
	double im; // 虚部

public:
	// 构造函数，允许隐式转换
	Complex(double r = 0, double i = 0)
		: re(r), im(i) {
	}
	// 访问函数，返回实部和虚部
	double getReal() const
	{
		return re;
	}
	double getImag() const
	{
		return im;
	}
	// 一元算术运算符，不改变原值，返回新对象,所以使用Complex而不是Complex&
	Complex operator+() const
	{
		return *this;
	}
	Complex operator-() const
	{
		return Complex(-re, -im);
	}

	// 复合赋值运算符，改变原值，返回当前对象的引用

	Complex& operator+=(const Complex& x)
	{
		re += x.re;
		im += x.im;
		return *this;
	}
	Complex& operator-=(const Complex& x)
	{
		re -= x.re;
		im -= x.im;
		return *this;
	}
	// 等价运算符，返回bool值
	friend bool operator==(const Complex& x, const Complex& y)
	{
		return (x.re == y.re) && (x.im == y.im);
	}
	friend bool operator!=(const Complex& x, const Complex& y)
	{
		return !(x == y);
	}

	// 二元算术运算符，不改变原值，返回新对象
	/*
	1. 作为成员函数时，可能在调用时隐式传递一个this指针作为第一个参数，因此只能重载左侧操作数为类类型的运算符。
	  Complex x,y,z;
	  z = x + y;x.operator+(y); // 隐式传递this指针
	  z= x + 7.5 ; x.operator+(7.5)--> x.operator+(Complex(7.5, 0.0)); // 隐式传递this指针
	  // 将double-7.5转换为Complex类型，然后调用成员函数,转换构造函数是单参数，可以进行隐式转换

	  z = 7.5 + x; // 7.5.operator+(x); // 错误，double不是类类型，不能调用成员函数
	  2. 作为友元函数时，两个参数都可以是类类型，也可以是基本类型。
	  z = x + y; operator+(x, y);
	  z = x + 7.5; operator+(x, Complex(7.5, 0.0));
	  z = 7.5 + x; operator+(Complex(7.5, 0.0), x);
	  3. z = 7.5 + 3.0; 
	  过程是：
	  因为编译器优先使用 内建类型的运算符重载，并且 double 之间本来就能直接相加，完全不需要转换成 Complex。
		● 先计算 7.5 + 3.0 → 得到 10.5（double）
		● 再将 double 隐式转换成 Complex（如果有 Complex(double) 构造函数）
		● 最后赋值给 z
		double tmp = 7.5 + 3.0; // 内置 double 加法
		z = Complex(tmp);       // 赋值前发生一次隐式转换
		4. z = 3 + x;
				3 是 int
				x 是 Complex
		C++ 做 运算符重载匹配：
		编译器先看有没有内置的 operator+ 可以匹配：左右都是内置类型？ ❌
		不是 → 考虑用户自定义类型转换   发现 Complex 有 Complex(double) 构造函数
		int → double → Complex（隐式构造）
		然后调用你的 friend operator+(Complex, Complex)
		所以：
		int → double 是标准类型提升（编译器自动做）
		double → Complex 是用户自定义隐式转换（通过构造函数）
	  */
	friend Complex operator+(const Complex& x, const Complex& y)
	{
		return Complex(x.re + y.re, x.im + y.im);
	}
	friend Complex operator+(double x, const Complex& y)
	{
		return Complex(x + y.re, y.im);
	}
	friend Complex operator+(const Complex& x, double y)
	{
		return Complex(x.re + y, x.im);
	}

};
// 在类外定义输出运算符， 可能需要访问私有成员，可以定义为友元函数，在类中包括一个隐式的this指针参数
inline std::ostream& operator<<(std::ostream& os, const Complex& x)
{
	os << "(" << x.getReal() << "," << x.getImag() << ")";
	return os;
}