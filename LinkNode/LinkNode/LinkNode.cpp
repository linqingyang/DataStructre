// LinkNode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define OK 1
#define ERROR -1
typedef int Status;
typedef int ElemType;

//单链表的存储结构
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//单链表的初始化
Status InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	std::cout << "单链表初始化完成" << std::endl;
	return OK;
}

//单链表的取值
Status GetElem(LinkList L,int i, ElemType &e) {
	LNode *p;
	p = L->next;
	int j = 1;
	while (p&&j<1)
	{
		p = p->next;
		++j;
	}
	if (!p||j>i) {
		return ERROR;
	}
	e = p->data;
	return OK;
}

//单链表的按值查找
LNode *LocateElem(LinkList L,ElemType e) {
	LNode *p;
	p = L->next;
	while (p&& p->data!=e) {
		p = p->next;
	}
	return p;
}

//单链表的插入
Status InsertList(LinkList &ll, int i) {
	ElemType e;
	LNode *p;
	p = ll;
	int j = 0;
	while (true)
	{

	}
}
//单链表的删除
//前插法创建单链表
//后插法创建单链表
int main()
{
    return 0;
}

