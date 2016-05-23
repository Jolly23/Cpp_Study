// cpptest3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
typedef int DATA;

using namespace std;
struct SNode
{
	DATA data;
	SNode *pNext;
};
class SList
{
public:
	SNode* m_pHead;
	
	SList()
	{	m_pHead = NULL;	}
	
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
	
	void AddHead(DATA d)
	{
		SNode *p = new SNode;
		p->data = d;
		p->pNext = m_pHead;
		m_pHead = p;
	}
	
	~SList()
	{
		SNode *p = m_pHead;
		SNode *p1;
		while(p)
		{
			p1 = p;
			p = p->pNext;
			delete p1;
		}
	}
};


int main(int argc, char* argv[])
{
	SList list1,list2;
	
	int Sel;
	DATA d;


	do
	{
		cout << "请输入数据：" << endl;
		cin  >> d;
		
		cout << "请选择要存入的链表（1或2）" << endl;
		cin  >> Sel;

		if(Sel == 0)
			break;
		
		if(Sel == 1)
			list1.AddHead(d);
		if(Sel == 2)
			list2.AddHead(d);

		cout << "list1.Count = " << list1.GetCount() << endl;
		cout << "list2.Count = " << list2.GetCount() << endl;
	
	}while(1);

	return 0;
}
