// Array.cpp: implementation of the CArray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Array.h"
#include <memory.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CArray::CArray()
{
	m_pData = new TYPE[32];
	memset(m_pData,0,sizeof(m_pData));
	m_nSize = 0;
	m_nCount= 32;
}

CArray::~CArray()
{	delete []m_pData;	}

int CArray::Add( TYPE data )
{
	if(m_nSize >= m_nCount)
		ReMalloc(m_nSize);
	m_pData[m_nSize] = data;
	++m_nSize;
	return m_nSize;
}

void CArray::ReMalloc(int nCount)
{
	m_nCount =nCount*2;
	TYPE *p = new TYPE[m_nCount];
	memset(p,0,sizeof(TYPE)*m_nCount);

	memcpy( p, m_pData, m_nSize*sizeof(TYPE) );
	delete []m_pData;
	m_pData = p;
}

void CArray::RemoveAll()
{
	delete []m_pData;
	CArray();
}

//Ä¬ÈÏÖ»É¾³ý1¸ö
void CArray::RemoveAt(int nIndex, int nCount /* = 1 */)
{
	if(nIndex >= m_nSize)
		return;

	if(nIndex+nCount  >= m_nSize)
	{
		m_nSize = nIndex;
		*(m_pData+nIndex+1) = '\0';
		return;
	}

	memcpy(m_pData+nIndex, m_pData+nIndex+nCount, sizeof(TYPE)*(m_nSize-nIndex-nCount));
	m_nSize -= nCount;
}

//void CArray::InsertAt(int nIndex, TYPE NewElements, int nCount /* = 1 */)
/*
{
	if(nIndex < 0)
		return;

	if(nCount+m_nSize >= m_nCount)
	{
		m_nCount = m_nSize;
		ReMalloc();
	}

	int i = 0;
	memcpy(m_pData+nIndex+nCount, m_pData+nIndex, sizeof(TYPE)*(m_nSize - nIndex));
	m_nSize += nCount;

	while(i < nCount)
		m_pData[nIndex + i++] = NewElements ;
}
*/
void CArray::InsertAt( int nIndex, TYPE data, int nCount )
{
	if(nCount<=0)
		return;
	if(nIndex<0)
		nIndex=0;
	if(nIndex>=m_nSize)
	{
		m_nSize = nIndex+nCount;
		if(m_nSize>m_nCount)
			ReMalloc(m_nSize);

	}
	else
	{
		m_nSize += nCount;
		if(m_nSize>m_nCount)
			ReMalloc(m_nSize);
		//&m_pData[nIndex+nCount]
		memcpy(m_pData+nIndex+nCount,m_pData+nIndex,sizeof(TYPE)*(m_nSize-nIndex));
	}
	int i = 0;
	while(i<nCount)
		m_pData[nIndex+i++]=data;
}

void CArray::Sort(TYPE *p)
{
	int i = 0, j = 0;
	while(i < this->GetSize() )
	{
		j = 0;
		while(j < this ->GetSize() - i - 1)
		{
			if(p[j] > p[j+1])
			{
				TYPE t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
			++j;
		}

		++i;
	}
}

void CArray::SetSize(int nNewSize)
{
	if(nNewSize < 0)
		nNewSize = 0;
	m_nSize = nNewSize;
	if(m_nSize > m_nCount)
		ReMalloc(m_nSize);
}
