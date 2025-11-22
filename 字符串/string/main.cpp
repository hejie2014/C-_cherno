#include <iostream>
#include <string>

int main()
{   
	std::string;
	const char* name = "hemu";
	char name2[6] = { 'h', 'e','m','u','!','\0' };
	char name3[] = "hemu!";
	name3[0] = 'a';
	std::cout << name3 << std::endl;
	std::cout << name3[0] << std::endl;
	std::cout << name3[4] << std::endl;
	std::cout << sizeof(name3) / sizeof(name[0]) << std::endl;
	const int var = 3;

	const int* a = new int(6);
	//*a = 5;
	/*
	这里 const int* a 表示 a 指向一个 const int，即不能通过 a 修改所指向的值，所以 *a = 5; 会报错。
	*/
	 const int* b = a;
	a = &var;
	//int* a = &var;
	std::cout << "===========" << std::endl;
	std::cout << *a << std::endl;
	delete b;
}