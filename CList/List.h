// List.h: interface for the CList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIST_H__4F394067_C867_46C1_8430_9AF3415868D4__INCLUDED_)
#define AFX_LIST_H__4F394067_C867_46C1_8430_9AF3415868D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef int DATA;

struct SNode
{
	DATA data;
	SNode*pPrev,*pNext;
};

typedef void* POSITION;

class CList  
{
	SNode* m_pHead,*m_pTail;
	int m_nCount;

public:
	POSITION GetHeadPosition() const
	{
		return m_pHead;
	}
	POSITION GetTailPosition() const
	{ 
		return m_pTail;
	}

	int GetCount() const
	{
		return m_nCount;
	}

	DATA GetAt(POSITION pos) const
	{
	     return ((SNode*)pos) ->data;
	}

	void AddTail(DATA data);
	void AddHead(DATA data);

	DATA GetNext(POSITION &pos);
	DATA GetPrev(POSITION &pos);

	void SetAt( POSITION pos, DATA data);
	void RemoveAt(POSITION pos);

	void RemoveAll();
	CList();
	~CList();
};

#endif // !defined(AFX_LIST_H__4F394067_C867_46C1_8430_9AF3415868D4__INCLUDED_)
