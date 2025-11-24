#include "idNo.h"


//定义静态成员变量，可以省略static
int IdNo::s_counter = 0;


IdNo::IdNo() : id_no(++s_counter) {
}

int IdNo::getIdNo() const
{
	return id_no;
}
//定义静态成员方法，可以省略static，但返回值类型和类名不能省略
// 不能访问非静态成员变量和方法
int IdNo::getMaxId()
{   
	return s_counter;
}