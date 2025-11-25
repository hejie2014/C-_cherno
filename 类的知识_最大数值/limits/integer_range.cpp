#include <iostream>
#include <limits>

int main()
{
	using namespace std;

	cout << "当前编译环境中字符类型为：" 
		<<(numeric_limits<char>::is_signed ? "有符号" : "无符号")
		<< "字符类型。"<<endl;

	cout << "当前编译环境中各整数类型的取值范围如下：" << endl;
	cout << "char 类型: " << int(numeric_limits<char>::min()) << " ~ " << int(numeric_limits<char>::max()) << endl;
	cout << "signed char: " << int(numeric_limits<signed char>::min()) << " ~ " << int(numeric_limits<signed char>::max()) << endl;

	cout << "unsigned char: " << int(numeric_limits<unsigned char>::min()) << " ~ " << int(numeric_limits<unsigned char>::max()) << endl;

	cout << "short 类型: " << numeric_limits<short>::min() << " ~ " << numeric_limits<short>::max() << endl;
	cout << "short int: " << numeric_limits<short int>::min() << " ~ " << numeric_limits<short int>::max() << endl;
	cout << "int: " << numeric_limits<int>::min() << " ~ " << numeric_limits<int>::max() << endl;
	cout << "long: " << numeric_limits<long>::min() << " ~ " << numeric_limits<long>::max() << endl;
	cout << "long int" << numeric_limits<long int>::min() << " ~ " << numeric_limits<long int>::max() << endl;
	cout << "long long: " << numeric_limits<long long>::min() << " ~ " << numeric_limits<long long>::max() << endl;
	cout << "long long int: " << numeric_limits<long long int>::min() << " ~ " << numeric_limits<long long int>::max() << endl;
	cout << "unsigned short int: " << numeric_limits<unsigned short int>::min() << " ~ " << numeric_limits<unsigned short int>::max() << endl;
	cout << "unsigned int: " << numeric_limits<unsigned int>::min() << " ~ " << numeric_limits<unsigned int>::max() << endl;
	cout << "unsigned long int: " << numeric_limits<unsigned long int>::min() << " ~ " << numeric_limits<unsigned long int>::max() << endl;

}
/*
当前编译环境中字符类型为：有符号字符类型。
当前编译环境中各整数类型的取值范围如下：
char 类型: -128 ~ 127
signed char: -128 ~ 127
unsigned char: 0 ~ 255
short 类型: -32768 ~ 32767
short int: -32768 ~ 32767
int: -2147483648 ~ 2147483647
long: -2147483648 ~ 2147483647
long int-2147483648 ~ 2147483647
long long: -9223372036854775808 ~ 9223372036854775807
long long int: -9223372036854775808 ~ 9223372036854775807
unsigned short int: 0 ~ 65535
unsigned int: 0 ~ 4294967295
unsigned long int: 0 ~ 4294967295
*/