// CMapTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef int DATA;
struct SNode
{
	DATA data;
	SNode* pNext;
};

SNode* g_pData[5] = {0};
void SatAt(const DATA &data)
{
	int n = data % 5;
	SNode *p = new SNode;
	p->data = data;
	p->pNext = g_pData[n];
	g_pData[n] = p;
}

void LookUp(const DATA &data)
{
	int n = data % 5;
	SNode *p = g_pData[n];

	while(p)
	{
		if(p->data == data){
			cout << "找到了，地址是" << &p->data << endl; 
			return;
		}
		p = p ->pNext;
	}
	cout << "没找到！" << endl;
}

int main(int argc, char* argv[])
{
	SatAt(15);
	SatAt(115);
	SatAt(153);
	SatAt(123);
	SatAt(453);
	SatAt(7);
	SatAt(12);
	SatAt(5823);
	SatAt(11);
	SatAt(28);
	SatAt(24);
	SatAt(94);
	SatAt(25);
	SatAt(16);
	SatAt(61);
	SatAt(25);
	SatAt(43);
	SatAt(52);


	LookUp(15);
	return 0;
}
