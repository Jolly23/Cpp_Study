// Stack.cpp: implementation of the CStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Stack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStack::CStack(int nCount)
{
	m_nCount = nCount;
	m_pData = new TYPE[nCount];
	m_nTop   = -1;
}

CStack::~CStack()
{
	delete []m_pData;
}

void CStack::ReApply()
{
	m_nCount *= 2;
	TYPE *m_pNew = new TYPE[m_nCount];
	int i = 0;
	while(i <= m_nTop)
	{
		m_pNew[i] = m_pData[i];
		++i;
	}
	delete m_pData;
	m_pData = m_pNew;
}
