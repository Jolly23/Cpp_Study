// Queue.h: interface for the CQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUEUE_H__593DBB11_2E87_45C7_8F27_7DF3883C79BD__INCLUDED_)
#define AFX_QUEUE_H__593DBB11_2E87_45C7_8F27_7DF3883C79BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//typedef int TYPE;
template <typename TYPE>
class CQueue  
{
	TYPE *m_pData;
	int m_nCount ;
	int m_nHead, m_nTail;
public:
	CQueue(int nCount = 8)
	{
		m_pData  = new TYPE[nCount];
		m_nCount = nCount;
		m_nHead  = 0;
		m_nTail  = 0;
	}
	~CQueue()
	{
		delete []m_pData;
	}
	
	bool isEmpty()
	{	return m_nHead == m_nTail;	}
	bool isFull()
	{	return (m_nTail + 1) % m_nCount == m_nHead ;	}

	void push(const TYPE &data)
	{
		if(isFull())
			return;
		m_pData[m_nTail++] = data;
		m_nTail %= m_nCount ;
	}
	
	bool pop(TYPE &t)
	{
		if(isEmpty())
			return false;
		t = m_pData[m_nHead++];
		m_nHead %= m_nCount ;
		return true;
	}
};

#endif // !defined(AFX_QUEUE_H__593DBB11_2E87_45C7_8F27_7DF3883C79BD__INCLUDED_)
