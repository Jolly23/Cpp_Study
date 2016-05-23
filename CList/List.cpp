// List.cpp: implementation of the CList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "List.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CList::CList()
{
	m_pHead  = NULL ;	
	m_pTail  = NULL ;
	m_nCount = 0    ;
}

CList::~CList()
{
	SNode *p = m_pHead, *p1;
	while(p)
	{
		p1 = p;
		p  = p ->pNext;
		delete p1;
	} 	
}

void CList::AddTail(DATA data)
{
	SNode *pNew  = new SNode;
	pNew ->data  = data;
	pNew ->pNext = NULL;
	pNew ->pPrev = m_pTail;

	if(m_pTail)
		m_pTail ->pNext = pNew;
	else
		m_pHead = pNew;
	
	m_pTail = pNew;
	++m_nCount;
}

void CList::AddHead(DATA data)
{
	SNode *pNew  = new SNode;
	pNew ->data  = data;
	pNew ->pNext = m_pHead;
	pNew ->pPrev = NULL;

	if(m_pHead)
		m_pHead ->pPrev = pNew;
	else
		m_pTail = pNew;
	
	m_pHead = pNew;
	++m_nCount;
}

DATA CList::GetNext(POSITION &pos)
{
	SNode *p = (SNode*)pos;
	pos = p ->pNext;
	return p->data;
}

DATA CList::GetPrev(POSITION &pos)
{
	SNode *p = (SNode*)pos;
	pos = p ->pPrev;
	return p->data;
}

void CList::SetAt( POSITION pos, DATA data)
{
	((SNode*)pos) ->data = data;
}

void CList::RemoveAt(POSITION pos)
{
	if( ((SNode*)pos)->pNext )
		(((SNode*)pos)->pNext)->pPrev = ((SNode*)pos)->pPrev;
	if( ((SNode*)pos)->pPrev )
		(((SNode*)pos)->pPrev)->pNext = ((SNode*)pos)->pNext;
	delete (SNode*)pos;

	--m_nCount;
}

void CList::RemoveAll()
{
	SNode *p = m_pHead, *p1;
	while(p)
	{
		p1 = p;
		p  = p ->pNext;
		delete p1;
	}
	m_pHead  = NULL;
	m_pTail  = NULL;
	m_nCount = 0;
}
