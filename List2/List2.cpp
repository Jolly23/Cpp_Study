// List2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <malloc.h>

typedef int DATA;

struct SNode
{
	DATA data;
	SNode *pNext;
}   *g_pHead = NULL;

void AddTail(DATA d)					//尾插法
{
	SNode *p	 =   g_pHead;
	SNode *pNew	 =   (SNode*)malloc(sizeof(SNode));
	pNew->data	 =   d;
	pNew->pNext  =   NULL;
	if(p == 0)
	{
		g_pHead  =   pNew;
		return;
	}
	while(p->pNext != NULL)
		p = p->pNext;
	p->pNext = pNew;
}

void AddHead(DATA d)					//头插法
{
	SNode *pNew	 =   (SNode*)malloc(sizeof(SNode));
	pNew->data	 =   d;
	pNew->pNext	 =   g_pHead;			//新节点后继
	g_pHead      =   pNew;				//头节点转移
}


void Print()							//输出
{
	SNode *p = g_pHead;
	while(p)
	{
		printf("%d\n",p->data);
		p = p->pNext;
	}
}
	
void Modify(int Old, int New)			//修改
{
	SNode *p = g_pHead;
	while(p)
	{
		if(p->data == Old)
			p->data = New;
		p = p->pNext;
	}
}

void Delete(int data)					//删除
{
	SNode *p = g_pHead, *p1;
	if(p->data == data)
	{
		g_pHead = p->pNext;
		free(p);
		return;
	}
	
	while(p)
	{
		if(p->data == data)
		{
			p1->pNext = p->pNext;
			free(p);
			break;
		}
		p1 = p;
		p = p->pNext;
	}
}

void main()
{
	AddTail(29);
	AddTail(5229);
	AddTail(1249);
	//	AddTail(29321);
	//	AddTail(49);
	//	AddTail(825469);
	//	AddTail(7279);
	//	AddHead(72);
	Modify(29,39);
	Delete(29);
	Print();
	system("pause");
}