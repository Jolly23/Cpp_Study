// Map1.cpp: implementation of the CMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Map1.h"
#include <stdio.h>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap::CMap()
{
	m_pRoot = NULL;
}

CMap::~CMap()
{
	RemoveAll();
}

void CMap::SetAt(SNode *&pNode,KEY key,VALUE value)
{
	if(!pNode)
		pNode = new SNode(value);
	else
	{
		if(key < pNode->key)
			SetAt(pNode->pL,value.nNumb,value);
		if(key > pNode->key)
			SetAt(pNode->pR,value.nNumb,value);
	}	
}

void CMap::SetAt(VALUE value)
{
	SetAt(m_pRoot,value.nNumb, value);
}

bool CMap::LookUp(SNode *pNode,KEY inkey,VALUE& rValue)
{
	if(!pNode)
		return false;
	if(pNode->key == inkey)
	{
		rValue = pNode->value;
		return true;
	}
	if(inkey < pNode->key)
		return LookUp(pNode->pL,inkey,rValue);
	else
		return LookUp(pNode->pR,inkey,rValue);
}
bool CMap::LookUp(KEY inkey,VALUE& rValue)
{
	return LookUp(m_pRoot,inkey,rValue);
}
VALUE& CMap::GetValue(SNode *pNode, KEY inkey)
{
	if(pNode->key == inkey)
		return pNode->value;
	if(inkey < pNode->key)
	{
		if(!pNode->pL)
			pNode->pL = new SNode(inkey);
		return GetValue(pNode->pL,inkey);
	}
	else
	{
		if(!pNode->pR)
			pNode->pR = new SNode(inkey);
		return GetValue(pNode->pR,inkey);
	}
}

VALUE& CMap::operator[](KEY inkey)
{
	if(m_pRoot)
		return GetValue(m_pRoot,inkey);

	m_pRoot = new SNode(inkey);
	return m_pRoot->value;
}

/*
bool CMap::RemoveKey( KEY key )
{
	return false;
}*/

void CMap::RemoveAll()
{
	if(m_pRoot){
		RemoveAll(m_pRoot);
		m_pRoot = NULL;
	}
}

void CMap::RemoveAll(SNode *pNode)
{
	if(pNode->pL)
		RemoveAll(pNode->pL);
	if(pNode->pR)
		RemoveAll(pNode->pR);
	delete pNode;
}

void CMap::PrintAll()
{
	PrintAll(m_pRoot);
}

void CMap::PrintAll(SNode *pNode)
{
	cout << "Ñ§ºÅ£º" << pNode->value.nNumb << "\tÐÕÃû£º" << pNode->value.sName << endl;
	if(pNode->pL)
		PrintAll(pNode->pL);
	if(pNode->pR)
		PrintAll(pNode->pR);
}
