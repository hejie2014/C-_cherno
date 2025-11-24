#pragma once
class IdNo {
private:
	static int s_counter; //现在编到第几号了，需要在类的外部进行初始化
	int id_no;  // 识别编号
public:
	IdNo();  
	int getIdNo() const; // 获取识别编号
	static int getMaxId();  // 获取当前最大识别编号
};