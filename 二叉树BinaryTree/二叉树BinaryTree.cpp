// ¶þ²æÊ÷BinaryTree.cpp : Defines the entry point for the console application.
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

void Order1(SNode* p)
{
	cout << (char)p->data << " ";
	if(p->pL)
		Order1(p->pL);
	if(p->pR)
		Order1(p->pR);
}

void Order2(SNode* p)
{
	if(p->pL)
		Order2(p->pL);
	cout << (char)p->data << " ";
	if(p->pR)
		Order2(p->pR);
}

void Order3(SNode* p)
{
	if(p->pL)
		Order3(p->pL);
	if(p->pR)
		Order3(p->pR);
	cout << (char)p->data << " ";
}

int main(int argc, char* argv[])
{
	SNode *p = new SNode('A');
	g_pRoot = p; //¸ù

	p->pL = new SNode('B');
	p->pL->pL = new SNode('C');
	p->pL->pL->pL = new SNode('H');
	p->pL->pL->pR = new SNode('I');
	p->pL->pR = new SNode('D');
	p->pL->pR->pL = new SNode('J');
	p->pL->pR->pR = new SNode('K');
	p->pR = new SNode('E');
	p->pR->pL = new SNode('F');
	p->pR->pL->pL = new SNode('L');
	p->pR->pL->pR = new SNode('M');
	p->pR->pR = new SNode('G');
	p->pR->pR->pL = new SNode('N');
	p->pR->pR->pR = new SNode('O');
	
	
	
	Order1(g_pRoot);
	cout << endl;

	return 0;
}
