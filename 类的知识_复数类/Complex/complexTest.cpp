#include <iostream>
#include "complex.h"


int main()
{
	using namespace std;
	double re, im;
	cout << "a的实部: "; cin >> re;
	cout << "a的虚部: "; cin >> im;
	Complex a(re, im);

	cout << "b的实部: "; cin >> re;
	cout << "b的虚部: "; cin >> im;
	Complex b(re, im);

	Complex c = -a + b;
	b += 2.0;   // b = b + 2.0;在b加上(2.0, 0.0)
	c -= Complex(1.0, 1.0);  // c = c - (1.0,1.0);在c减去(1.0, 1.0)
	Complex d(b.getImag(), c.getReal()); // d的实部是b的虚部，d的虚部是c的实部


	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d<< endl;
	/*
	a的实部: 1.2
	a的虚部: 3.5
	b的实部: 4.6
	b的虚部: 7.1
	a = (1.2,3.5)
	b = (6.6,7.1)
	c = (2.4,2.6)
	d = (7.1,2.4)
	*/
}