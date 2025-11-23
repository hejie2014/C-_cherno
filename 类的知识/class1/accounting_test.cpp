#include <iostream>
#include "accounting.h"

using namespace std;


int main()
{
	Accounting account("Alice", 10000, 1990, 5, 15);
	Accounting account2("Bob", 5000, 1985, 10, 20);


	account.setEarn(300);  // 账户1增加收入300
	account2.setSpend(200); // 账户2支出200

	cout << "Alice\n";
	cout << "Name: " << account.getName() << endl;
	cout << "Asset: " << account.getAsset() << '$' << endl;
	cout << "Birthday: " << account.getBirthday().getYear() << '-'
						<< account.getBirthday().getMonth() << '-'
						<< account.getBirthday().getDay() << endl;

	cout << "Bob\n";
	cout << "Name: " << account2.getName() << endl;
	cout << "Asset: " << account2.getAsset() << '$' << endl;
	// account.getBirthday() 返回Date对象--调用重载的<<运算符
	// std::ostream& operator<<(std::ostream& os, const Date& date);
	cout << "Birthday: " << account2.getBirthday() << endl;


}