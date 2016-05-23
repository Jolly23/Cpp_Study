// cppHW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>

using namespace std;

struct SNode
{
	int data;
	SNode *pNext;
};

struct SList
{
	SNode *m_pHead;
	
	SList()
	{	
//		memset(this,0,sizeof(SList));
		m_pHead = NULL;
	}

	int GetCount()
	{
		int i = 0;
		SNode *p = m_pHead;
		while(p)
		{
			++i;
			p = p->pNext;
		}
		return i;
	}
	
	void AddHead(int indata)
	{
		SNode *pNew = new SNode;
		pNew->data  = indata;
		pNew->pNext = m_pHead;
		m_pHead = pNew;
	}
	
	~SList()
	{
		SNode *p = m_pHead, *p1;
		while(p)
		{
			p1 = p;
			p = p->pNext;
			delete p1;
		}
	}
};

void Print(SList *list)
{
	SNode *plist = list->m_pHead;
	if(!plist)
		cout << "list 空" << endl;
	while(plist)
	{
		cout << "list.DATA:  " << plist->data << endl;
		plist = plist->pNext;
	}
}

void Menu(SList *list)
{
	char Sel;
	int data;
	cout << "1、插入数据" << endl;
	cout << "2、打印数据" << endl;
	cout << "3、打印节点数量" << endl;
	Sel = getch();
	switch(Sel)
	{
	case '1':
		data = rand() % 100 +1;
		list ->AddHead(data);
		break;
	case '2':
		Print(list);
		system("pause");
		break;
	case '3':
		cout << "list.GetCount = " << list ->GetCount() <<endl;
		system("pause");
		break;
	}
}


int main(int argc, char* argv[])
{
	SList list;
	do
	{
		system("cls");
		Menu(&list);	
	}	while(true);
	
	return 0;
}
