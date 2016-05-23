// Stud.cpp: implementation of the CStud class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Stud.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SNode* m_pHead = NULL;

CStud::CStud()
{	m_pHead = NULL;	}

CStud::~CStud()
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

int CStud::GetCount()
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

void CStud::AddHead(int d)
{
	SNode *p = new SNode;
	p->data = d;
	p->pNext = m_pHead;
	m_pHead = p;
}


