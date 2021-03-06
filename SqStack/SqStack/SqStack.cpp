// SqStack.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define OK 1
#define ERROR -1
#define MAXSIZE 10
typedef int ELemType;
typedef int Status;
//定义结构体
typedef struct SqlStack {
	ELemType *base;
	ELemType *top;
	int stacksize;
}sqStack;
//顺序栈初始化操作
Status InitStack(sqStack &s) {
	s.base = new ELemType[MAXSIZE];
	if (!s.base) {
		std::cout << "	该顺序栈不为空，初始化失败" << std::endl;
		exit(OVERFLOW);
	}
	s.top = s.base;
	s.stacksize = MAXSIZE;
	std::cout << "	该顺序栈初始化成功" << std::endl;
	return OK;
}
//顺序栈入栈操作
Status Push(sqStack &s, ELemType e) {
	if (s.top-s.base==MAXSIZE) {
		std::cout << "	该顺序栈已经满了，无法再执行入栈操作"<<std::endl;
	}
	*s.top++ = e;
	std::cout << "	元素已经成功入栈" << std::endl;
	return OK;
}
//顺序栈出栈操作
Status Pop(sqStack &s, ELemType &e) {
	if (s.top==s.base) {
		std::cout << "	该顺序栈已经空了，无法再执行出栈操作" << std::endl;
		return ERROR;
	}
	e = *--s.top;
	std::cout << "	元素已成功出栈" << std::endl;
	return OK;
}
//顺序栈取栈元素操作
Status GetTOP(sqStack s) {
	if (s.top!=s.base) {
		std::cout << "	已取到元素" << std::endl;
		return *(s.top-1);
	}
	return OK;
}
int main()
{
	SqlStack ss;
	while (1)
	{
		int operate;
		std::cout << "				请选择想要执行的操作"<<std::endl;
		std::cout << "	1****初始化	2****入栈	3****出栈	4****取得栈顶元素 5****退出程序" << std::endl;
		std::cin >> operate;
		switch (operate)
		{
		case 1:
			InitStack(ss);
			break;
		case 2:
			int x;
			std::cout << "	请输入一个需要入栈的元素" << std::endl;
			std::cin >> x;
			Push(ss, x);
			break;
		case 3:
			Pop(ss, operate);
			break;
		case 4:
			std::cout << "当前栈顶元素是:" << GetTOP(ss)<< std::endl;
			break;
		case 5:
			exit(0);
			break;
		default:
			break;
		}
	}
	
	system("Pause");
    return 0;
}

