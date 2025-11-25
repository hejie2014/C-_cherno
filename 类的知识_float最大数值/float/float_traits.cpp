#include <iostream>
#include <limits>


int main()
{
	using namespace std;

	cout << "double最小值: " << numeric_limits<double>::min() << endl;
	cout << "double最大值: " << numeric_limits<double>::max() << endl;
	cout << "float最小值: " << numeric_limits<float>::min() << endl;
	cout << "float最大值: " << numeric_limits<float>::max() << endl;
	cout << "long double最小值: " << numeric_limits<long double>::min() << endl;
	cout << "long double最大值: " << numeric_limits<long double>::max() << endl;
	cout << "尾数部分" << numeric_limits<long double>::radix << "进制"
		<< numeric_limits<long double>::digits << "位" << endl;
	cout << "指数部分" << numeric_limits<long double>::min_exponent
		<< "到" << numeric_limits<long double>::max_exponent << endl;
	cout << "最小正归一化值"
		<< numeric_limits<long double>::min() << endl;
	cout << "位数" << numeric_limits<long double>::digits10 << "位十进制数"
		<< endl;
	cout << "机器精度" << numeric_limits<long double>::epsilon() << endl;
	cout << "最大舍入误差" << numeric_limits<long double>::round_error() << endl;
	cout << "舍入方式： ";
	switch (numeric_limits<long double>::round_style)
	{
	case round_indeterminate:
		cout << "不确定" << endl;
		break;
	case round_toward_zero:
		cout << "向零舍入" << endl;
		break;
	case round_to_nearest:
		cout << "舍入为可显示的最接近的值" << endl;
		break;
	case round_toward_infinity:
		cout << "向正无穷大舍入" << endl;
		break;
	case round_toward_neg_infinity:
		cout << "向负无穷大舍入" << endl;
		break;
	}

	cout << "=================" << endl;
	cout << "是否支持非正规化数: "
		<< (numeric_limits<long double>::has_denorm ? "是" : "否") << endl;
	cout << "非正规化数的最小值: "
		<< numeric_limits<long double>::denorm_min() << endl;
	cout << "是否支持无穷大和NaN: "
		<< (numeric_limits<long double>::has_infinity ? "是" : "否") << endl;
	cout << "正无穷大: "
		<< numeric_limits<long double>::infinity() << endl;
	cout << "NaN: "
		<< numeric_limits<long double>::quiet_NaN() << endl;
	cout << "是否支持舍入: "
		<< (numeric_limits<long double>::is_iec559 ? "是" : "否") << endl;
	cout << "是否支持负数: "
		<< (numeric_limits<long double>::is_signed ? "是" : "否") << endl;
	cout << "是否是整数类型: "
		<< (numeric_limits<long double>::is_integer ? "是" : "否") << endl;
	cout << "是否是精确表示: "
		<< (numeric_limits<long double>::is_exact ? "是" : "否") << endl;
	cout << "是否是有限表示: "
		<< (numeric_limits<long double>::is_bounded ? "是" : "否") << endl;
	cout << "是否是模糊表示: "
		<< (numeric_limits<long double>::is_modulo ? "是" : "否") << endl;
	cout << "最小十进制指数: "
		<< numeric_limits<long double>::min_exponent10 << endl;
	cout << "最大十进制指数: "
		<< numeric_limits<long double>::max_exponent10 << endl;
	cout << "十进制精度: "
		<< numeric_limits<long double>::digits10 << endl;
	cout << "最大十进制精度: "
		<< numeric_limits<long double>::max_digits10 << endl;
	cout << "是否是IEC 559标准: "
		<< (numeric_limits<long double>::is_iec559 ? "是" : "否") << endl;
}
/*
最小值2.22507e-308
最小值1.79769e+308
尾数部分2进制53位
指数部分-1021到1024
最小正归一化值2.22507e-308
位数15位十进制数
机器精度2.22045e-16
最大舍入误差0.5
舍入方式： 舍入为可显示的最接近的值
=================
是否支持非正规化数: 是
非正规化数的最小值: 4.94066e-324
是否支持无穷大和NaN: 是
正无穷大: inf
NaN: nan
是否支持舍入: 是
是否支持负数: 是
是否是整数类型: 否
是否是精确表示: 否
是否是有限表示: 是
是否是模糊表示: 否
最小十进制指数: -307
最大十进制指数: 308
十进制精度: 15
最大十进制精度: 17
是否是IEC 559标准: 是

flaot:
最小值1.17549e-38
最小值3.40282e+38
尾数部分2进制24位
指数部分-125到128
最小正归一化值1.17549e-38
位数6位十进制数
机器精度1.19209e-07
最大舍入误差0.5
舍入方式： 舍入为可显示的最接近的值
=================
是否支持非正规化数: 是
非正规化数的最小值: 1.4013e-45
是否支持无穷大和NaN: 是
正无穷大: inf
NaN: nan
是否支持舍入: 是
是否支持负数: 是
是否是整数类型: 否
是否是精确表示: 否
是否是有限表示: 是
是否是模糊表示: 否
最小十进制指数: -37
最大十进制指数: 38
十进制精度: 6
最大十进制精度: 9
是否是IEC 559标准: 是

*/