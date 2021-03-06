// SqlList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define OK 1
#define ERROR -1
#define MAXSIZE 20
typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *elem; //存储的是数组的第一个元素的位置
	ElemType data[MAXSIZE]; //数组存储数据元素最大值为MaxSize
	int length;  //顺序表的当前长度
}SqlList; //定义了结构体数据类型Sqlist，用于表示顺寻表

//初始化线性表操作
Status InitList(SqlList &l) {
	l.elem = new ElemType[MAXSIZE];
	if (!l.elem) {
		exit(OVERFLOW);
	}
	else
	{
		l.length = 0;
		std::cout << "初始化数组完成， " << "长度为0" << std::endl;
		return OK;
	}
}

//获取线性的元素操作
Status GetElem(SqlList l,int i) {
	ElemType e;
	if (l.length == 0 || i<1 || i>l.length) {
		std::cout << "输入的值下标越界" << std::endl;
		return ERROR;
	}
	else {
		e = l.elem[i-1];
		std::cout << "元素获取成功 " << e << std::endl;
		return OK;
	}
}
//顺序表的查找
Status LocateElemType(SqlList sl,ElemType e) {
	for (int i = 0; i < sl.length;i++) {
		if (sl.elem[i] == e) {
			i += 1;
			std::cout<<"位于第"<<i<<"个元素"<<std::endl;
			return i;
		}
	}
	return OK;
}
//顺序表的插入操作
Status InsertList(SqlList &sl, ElemType e, int i) {
	if (i<1 ) {
		std::cout << "输入的i值小于1,请重新输入" << std::endl;
		return ERROR;
	}
	else if (i>sl.length+1)
	{
		std::cout << "输入的i值大于顺序表长度,请重新输入" << std::endl;
		return ERROR;
	}
	else if (sl.length==MAXSIZE)
	{
		std::cout << "当前存储空间已满,，无法进行插入操作" << std::endl;
		return ERROR;
	}
	else
	{
		for (int j = sl.length - 1; j >= i - 1; j--) {
			sl.elem[j + 1] = sl.elem[j];
		}
		sl.elem[i - 1] = e;
		++sl.length;
	}
	return OK;
}
//顺序表删除操作
Status DeleteList(SqlList &sl, int i) {
	if (i<1) {
		std::cout << "输入的i值小于1,请重新输入" << std::endl;
		return ERROR;
	}
	else if (i>sl.length)
	{
		std::cout << "输入的i值大于顺序表长度,请重新输入" << std::endl;
		return ERROR;
	}
	else if (sl.length == 0)
	{
		std::cout << "当前存储空间已空,，无法进行删除操作" << std::endl;
		return ERROR;
	}
	else
	{
		for (int j = i; j < sl.length - 1;j++) {
			sl.elem[j - 1] = sl.elem[j];
		}
		--sl.length;
	}
	return OK;
}
int main()
{
	int operate;
	int x;
	SqlList sl;
	while (true)
	{
		std::cout << "请选择需要进行的操作" << std::endl;
		std::cout << "1****初始化	2****取值	3****查找	4****插入	5****删除	6****退出" << std::endl;
		std::cin >> operate;
		switch (operate)
		{
		case 1:
			InitList(sl);
			break;
		case 2:
			std::cout << "请输入查找第几个元素" << std::endl;
			std::cin >> x;
			GetElem(sl, x);
			break;
		case 3:
			int y;
			std::cout << "请输入查找元素的值" << std::endl;
			std::cin >> y;
			LocateElemType(sl, y);
			break;
		case 4:
			int z;
			ElemType e;
			std::cout << "请输入要插入的元素" << std::endl;
			std::cin >> e;
			std::cout << "请输入要插入的位置" << std::endl;
			std::cin >> z;
			InsertList(sl,e, z);
			break;
		case 5:
			std::cout << "请输入要删除的元素" << std::endl;
			std::cin >> e;
			DeleteList(sl, e);
			break;
		case 6:
			exit(0);
			break;
		default:
			break;
		}
	}
	system("Pause");

    return 0;
}

