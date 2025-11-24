#include <iostream>
#include "idNo.h"

using namespace std;
int main()
{
	IdNo a;
	IdNo b;
	IdNo c[4];

	cout << "a's 'ID:' " << a.getIdNo() << endl;
	cout << "b's ID: " << b.getIdNo() << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "c[" << i << "]'s ID: " << c[i].getIdNo() << endl;
	}
	cout << "Max ID: " << IdNo::getMaxId() << endl;
}