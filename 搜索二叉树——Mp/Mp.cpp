// Mp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
typedef int DATA;

struct SNode
{
	DATA data;
	SNode *pL,*pR;
	SNode(DATA d):data(d)
	{
		pL = pR = NULL;
	}
};
SNode *g_pRoot = NULL;

void SetAt(SNode *&pNode, DATA data)
{
	if(!pNode)
		pNode = new SNode(data);
	else
	{
		if(data < pNode->data)
			SetAt(pNode->pL,data);
		if(data > pNode->data)
			SetAt(pNode->pR,data);
	}
}

void SetAt(DATA data)
{
	SetAt(g_pRoot,data);
}

bool Lookup(SNode *pNode,DATA data)
{
	if(!pNode)
		return false;
	if(pNode->data == data)
		return true;
	if(data < pNode->data)
		return Lookup(pNode->pL,data);
	else
		return Lookup(pNode->pR,data);
}

bool Lookup(DATA data)
{
	return Lookup(g_pRoot,data);
}

void Order1(SNode* p);

int main(int argc, char* argv[])
{
	SetAt(213);
	SetAt(34);
	SetAt(534);
	SetAt(56);
	SetAt(4);
	SetAt(768);
	SetAt(23);
	SetAt(565);
	SetAt(667);
	SetAt(87);
	SetAt(234);
	SetAt(765);
	SetAt(27);
	if(Lookup(765) == true)
		cout << "找到了！" << endl;
	else
		cout << "没找到！" << endl;

	cout << endl << "全部数据：" << endl;
	Order1(g_pRoot);
	return 0;
}

void Order1(SNode* p)
{
	cout << p->data << " ";
	if(p->pL)
		Order1(p->pL);
	if(p->pR)
		Order1(p->pR);
}
