#pragma once

#include <iostream>


class Boolean {
public:
	// 定义枚举类型表示布尔值
	enum boolean_t {
		False = 0, True = 1
	};
private:
	// 成员变量存储布尔值
	boolean_t m_value;
public:
	// 默认构造函数，初始化为 False
	Boolean() : m_value(False) {}
	// 构造函数，根据整数值初始化布尔值
	Boolean(int val) : m_value(val == 0 ? False : True) {}
	// 转换运算符，将 Boolean 转换为整数
	operator int() const {
		//return m_value == True ? 1 : 0;
		return m_value;
	}
	// 转换运算符，将 Boolean 转换为const char* （字符串）
	operator const char* () const
	{
		return m_value == True ? "True" : "False";
	}
	// 逻辑非运算符，返回布尔值的相反值，即 True 变 False，False 变 True
	// 返回一个新的 Boolean 对象
	Boolean operator!() const {
		return Boolean(m_value == True ? False : True);
	}
};
// 重载输出流运算符，用于打印 Boolean 对象, 使用inline关键字，防止多重定义错误
inline std::ostream& operator<<(std::ostream& os, const Boolean& x)
{   
	// 将boolean对象转换为const char*并输出
	os << static_cast<const char*> (x);
	// 返回输出流对象以支持链式调用
	return os;
}