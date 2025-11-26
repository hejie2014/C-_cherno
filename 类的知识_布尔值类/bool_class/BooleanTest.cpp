#include <iostream>
#include "boolean.h"


// 判断两个整数是否相等，返回 Boolean 类型的结果
Boolean int_eq(int x, int y)
{
	return x == y;
}


int main()
{
	int n = 0;
	Boolean a;  // 默认的构造函数，False
	Boolean b = a;  // 拷贝构造函数，b 也是 False
	Boolean c = 100; // 整数转换构造函数，非零值为 True
	Boolean x[8];  // Boolean 类型的数组，默认初始化为 False

	int test1 = a;  // 隐式转换，调用int的转换函数转为int
	int test2 = c;
	std::cout << "test1: " << test1 << ", test2: " << test2 << std::endl;
	const char* test3 = a; //  隐式转换，调用const char*的转换函数
	const char* test4 = c;
	std::cout << "test3: " << test3 << ", test4: " << test4 << std::endl;

	std::cout << "请输入一个整数： ";
	std::cin >> n;
	x[0] = int_eq(n, 3);  // 调用函数，将结果赋值给 x[0]
	x[1] = (n != 3);  // Boolean(n !=3)
	x[2] = Boolean::False;  // 直接使用枚举值 False
	x[3] = 1000;   // Boolean(1000)
	x[4] = c == Boolean::True;  // Boolean(c == True)

	std::cout << "a: " << int(a) << std::endl;
	std::cout << "b: " << static_cast<const char*>(b) << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "x[" << i << "] = " << x[i] << std::endl;
	}
	/*
	请输入一个整数： 3
		a: 0
		b: False
		x[0] = True
		x[1] = False
		x[2] = False
		x[3] = True
		x[4] = True
		x[5] = False
		x[6] = False
		x[7] = False
	
	*/


	//Boolean b1;           // Default constructor, should be False
	//Boolean b2(1);        // Initialize with True
	//Boolean b3(0);        // Initialize with False
	//Boolean b4(42);       // Non-zero should be True
	//std::cout << "b1: " << b1 << " (int: " << static_cast<int>(b1) << ")\n";
	//std::cout << "b2: " << b2 << " (int: " << static_cast<int>(b2) << ")\n";
	//std::cout << "b3: " << b3 << " (int: " << static_cast<int>(b3) << ")\n";
	//std::cout << "b4: " << b4 << " (int: " << static_cast<int>(b4) << ")\n";
	//Boolean b5 = !b2;    // Negation of True should be False
	//Boolean b6 = !b3;    // Negation of False should be True
	//std::cout << "b5 (not b2): " << b5 << " (int: " << static_cast<int>(b5) << ")\n";
	//std::cout << "b6 (not b3): " << b6 << " (int: " << static_cast<int>(b6) << ")\n";
	return 0;
}
/*
b1: False (int: 0)
b2: True (int: 1)
b3: False (int: 0)
b4: True (int: 1)
b5 (not b2): False (int: 0)
b6 (not b3): True (int: 1)

*/

