// LNode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define OK 1;
#define ERROR -1;
typedef int Status;
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//单链表的初始化
Status InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	std::cout << "单链表已初始化" << L << std::endl;
	return OK;
}
//单链表的取值
Status GetElem(LinkList L,int i ,ElemType &e) {
	
	LNode *p = L->next;
	int j = 1;
	InitList(p);
	while (p&&j > 1) 
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}
//获得单链表的长度
Status GetLen(LinkList L) {
	Status len = 0;
	LNode* p = L;
	if (L == NULL)
		return ERROR;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	std::cout << "单链表的长度为: " << len << std::endl;
	return len;
}
	//打印单链表
Status PrintList(LinkList L) {
	LinkList p = nullptr;
    if (L == NULL)
        return ERROR;
    p = L->next;
    while (p)
    {
        std::cout <<"当前单链表中的元素有: "<< p->data << std::endl;
        p = p->next;
    }
    if (!p)
        return ERROR;
    return OK;
}
//单链表的取值
Status GetElem(LinkList ll, ElemType i) {
	//用e来返回单链表中的第几个元素
	ElemType e;
	LinkList p = ll->next;
	int j = 1;
	while (p&&j)
	{
		p = p->next;
		j += 1;
	}
	if (!p||j>i) {
		return ERROR;
	}
	e = p->data;
	std::cout << "该元素在单链表的位置是: " <<j<< std::endl;
	return OK
}
//单链表的按值查找
Status LocateList(LinkList ll , ElemType e ) {
	LinkList p;
	p = ll->next;
	while (p && p ->next)
	{
		p = p->next;
	}
	std::cout << "找到元素的地址为: " <<p<< std::endl;
	return OK;

}
//单链表的插入
Status InsertList(LinkList &ll, ElemType i , ElemType e) {
	LinkList p = ll;
	int j = 0;
	while (p && (j<i-1))
	{
		p = p->next;
		j++;
	}
	if (!p || (j>i-1)) {
		return ERROR;
	}
	LinkList s = new LNode;
	s->data = e;  //将e的值赋给s
	s->next = p->next; // 将s的指针指向e
	p->next = s;
	std::cout << "元素已经插入成功" << std::endl;
	return OK;
}
//单链表的删除
Status DeleteList(LinkList &ll, ElemType i) {
	LinkList p = ll;
	int j = 0;
	while ((p ->next) && (j<i-1))
	{
		p = p->next;
		++j;
	}
	if (!(p->next)||(j>i-1)) {
		return ERROR;
	}
	LinkList q;
	q = p->next;
	p->next = q->next;
	delete q;
	std::cout << "元素已经删除成功" << std::endl;
	return OK;
}
int main()
{
	LinkList ls;
	InitList(ls);
	std::cout << "已经默认初始化" << std::endl;
	while (1)
	{
		int operate;
		std::cout << "				请选择想要执行的操作" << std::endl;
		std::cout << "1****插入	2****删除	3****输出 4****求长度 5****退出程序" << std::endl;
		std::cin >> operate;
		switch (operate)
		{
		case 1:
			int x, y;
			std::cout << "	请输入一个需要插入的元素" << std::endl;
			std::cin >> x;
			std::cout << "	请输入一个需要插入的位置" << std::endl;
			std::cin >> y;
			InsertList(ls, y, x);
			break;
		case 2:
			std::cout << "	请输入要删除的第几个元素" << std::endl;
			std::cin >> x;
			DeleteList(ls, x);
			break;
		case 3:
			PrintList(ls);
			break;
		case 4:
			GetLen(ls);
			break;
		case 5:
			exit(0);
		default:
			break;
		}
	}
	system("pause");
    return 0;
}

