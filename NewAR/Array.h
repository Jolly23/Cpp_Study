// Array.h: interface for the CArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARRAY_H__FF844D29_791B_40B0_9D9A_9785348F22AA__INCLUDED_)
#define AFX_ARRAY_H__FF844D29_791B_40B0_9D9A_9785348F22AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef int TYPE;

class CArray  
{
private:
	void ReMalloc(int nCount);
	int m_nSize;	//有效数据
	int m_nCount;	//资源数量
	TYPE* m_pData;

public:
	void SetSize(int nNewSize);
	void Sort(TYPE *p);
	void InsertAt(int nIndex, TYPE data, int nCount =1);
	void RemoveAt(int nIndex, int nCount = 1);
	void RemoveAll();

	int GetSize() const
		{	return m_nSize;	}

	TYPE& GetAt(int nIndex)
		{	return m_pData[nIndex];	}

	TYPE& operator []( int nIndex )
		{	return m_pData[nIndex];	}

	//只读对象专用
	TYPE  GetAt(int nIndex) const
		{	return m_pData[nIndex];	}

	//只读对象专用
	TYPE operator []( int nIndex ) const
		{	return m_pData[nIndex];	}

	void SetAt(int nIndex, TYPE data)
		{	m_pData[nIndex] = data;	}

	int Add( TYPE data );

	const TYPE* GetData( ) const
	{//只读对象专用（const CArray &ar）
		return m_pData;
	}

	TYPE* GetData( )
	{
		return m_pData;
	}


	CArray();
	virtual ~CArray();
};

#endif // !defined(AFX_ARRAY_H__FF844D29_791B_40B0_9D9A_9785348F22AA__INCLUDED_)
