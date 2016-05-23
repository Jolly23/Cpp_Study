// Stack.h: interface for the CStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACK_H__4EA60A0B_40D2_4726_9FBC_8FB16C25818D__INCLUDED_)
#define AFX_STACK_H__4EA60A0B_40D2_4726_9FBC_8FB16C25818D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum{COUNT = 8};
typedef int TYPE;

class CStack  
{
	TYPE *m_pData;
	int m_nTop;
	int m_nCount;
public:
	CStack(int nCount = 8);
	~CStack();
	bool isFull()
	{
		return m_nTop+1 >= m_nCount;
	}
	
	bool isEmpty()
	{
		return	m_nTop < 0;
	}
	
	void CStack::push(const TYPE &data)		//��ջ
	{
		if(isFull())
			ReApply();
		m_pData[++m_nTop] = data;
	}

/*	const TYPE &pop()				//��ջ
	{
		if(m_nTop == -1)
			return -1;
		return m_pData[m_nTop--];
	}*/
	bool pop(TYPE &t)
	{
		if(isEmpty())
			return false;
		t = m_pData[m_nTop--];
		return true;
	}


private:
	void ReApply();
};

#endif // !defined(AFX_STACK_H__4EA60A0B_40D2_4726_9FBC_8FB16C25818D__INCLUDED_)