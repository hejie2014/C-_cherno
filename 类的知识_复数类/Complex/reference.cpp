#include <iostream>


//int main()
//{
//	double  d = 1.2;
//	double  r = 1.2;
//	const int& p = 5; // 常量引用可以绑定到字面值
//	const int& q = d; // 常量引用可以绑定到不同类型的变量，进行隐式类型转换
////	const double& r = d; // 常量引用绑定到同类型变量
//
//	d = 2.0; // 修改d的值
//	//const_cast<int&>(q) = 3.14; // 常量引用不能修改其绑定的值，使用const_cast去掉const属性，但结果未定义
//	std::cout << "d = " << d << std::endl;
//	std::cout << "p = " << p<< std::endl;
//	std::cout << "q = " << q << std::endl; // 输出q的值，结果未定义
//	std::cout << "r = " << r << std::endl;
//
//	//int a = 10;
//	// int& ref = a; // ref是a的引用
//	//std::cout << "a = " << a << std::endl;       // 输出a的值
//	//std::cout << "ref = " << ref << std::endl;   // 输出ref的值
//	//ref = 20; // 通过引用修改a的值
//	//std::cout << "After modifying ref:" << std::endl;
//	//std::cout << "a = " << a << std::endl;       // 输出修改后的a的值
//	//std::cout << "ref = " << ref << std::endl;   // 输出ref的值
//	//return 0;
//	/*
//	a = 10
//	ref = 10
//	After modifying ref:
//	a = 20
//	ref = 20
//	*/
//}