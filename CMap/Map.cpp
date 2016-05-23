// Map.cpp: implementation of the CMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Map.h"
#include <memory.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap::CMap(int nHashSize)
{
	m_nHashSize = nHashSize;
	m_pData = new SNode*[nHashSize];
	memset(m_pData,0,sizeof(SNode*)*nHashSize);
}

CMap::~CMap()
{
	RemoveAll();
	delete []m_pData; 
}

void CMap::SetAt(KEY key,VALUE value)
{
	int n = key % m_nHashSize;
	SNode *p = m_pData[n],*pPrev;
	while(p)
	{
		if(p->key == key)
		{
			p->value = value;
			return;
		}
		pPrev = p;
		p = p->pNext;
	}
// ͷ�巨
/*	SNode *pNew = new SNode;
	pNew->key = key;
	pNew->value = value;
	pNew->pNext = m_pData[n];
	m_pData[n] = pNew;
*/
//β�巨
	SNode *pNew = new SNode;
	pNew->key = key;
	pNew->value = value;
	pNew->pNext = 0;
	if(m_pData[n])
		pPrev->pNext = pNew;
	else
		m_pData[n] = pNew;
}

bool CMap::LookUp(KEY key, VALUE& rValue) const
{
	int n = key % m_nHashSize;
	SNode *p = m_pData[n];
	while(p)
	{
		if(p->key == key){
			rValue = p->value;
			return true;
		}
		p = p->pNext;
	}
	return false;
}

VALUE& CMap::operator[](KEY key )
{
	int n = key % m_nHashSize;
	SNode *p = m_pData[n],*pPrev;
	while(p)
	{
		if(p->key == key)
			return p->value ;
		pPrev = p;
		p = p ->pNext;
	}
	SNode *pNew = new SNode;
	pNew->key = key;
	pNew->pNext = 0;
	if(m_pData[n])
		pPrev->pNext = pNew;
	else
		m_pData[n] = pNew;
	return pNew->value;
}

bool CMap::RemoveKey( KEY key )
{
	int n = key & m_nHashSize;
	SNode *p = m_pData[n],*p1;
	while(p)
	{
		if(p->key == key){
			if(p1){
				p1->pNext = p->pNext;
				delete p;
				return true;
			}
			else{
				m_pData[n] = p->pNext;
				return true;
			}
		}	
		p1 = p;
		p = p->pNext;
	}
	return false;
}

void CMap::RemoveAll()
{
	int i = m_nHashSize;
	while(i--)
	{
		SNode *p = m_pData[i],*p1;
		while(p)
		{
			p1 = p;
			p = p->pNext;
			delete p1;
		}
		m_pData[i] = 0;
	}
}