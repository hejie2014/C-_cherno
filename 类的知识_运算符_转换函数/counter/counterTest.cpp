#include <iostream>
#include "counter.h"

using namespace std;

int main()
{
	int number;
	Counter x;
	cout << "当前的计数值： " << x << endl;

	cout << "增加计数的次数： ";
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		x.increment();
		cout << x << endl;
	}
	cout << "减少计数的次数： ";
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		x.decrement();
		cout << x<< endl;
	}
}