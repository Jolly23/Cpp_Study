// Map.h: interface for the CMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP_H__C9D3DD12_F648_4D8D_BD3A_E670D142C8E5__INCLUDED_)
#define AFX_MAP_H__C9D3DD12_F648_4D8D_BD3A_E670D142C8E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct Stud
{
	int nNumb;
	char sName[20];
	double dMath;
};

typedef int KEY;
typedef Stud VALUE;
enum {COUNT = 17};
struct SNode
{
	KEY key;
	VALUE value;
	SNode* pNext;
};


class CMap  
{//作业中要求根据构造函数指定的HashSize在堆上申请指针数组
	SNode *m_pRoot;
public:
	void SetAt(KEY key,VALUE value);
	bool LookUp(KEY key,VALUE& rValue) const;

	VALUE& operator[](KEY key );
	bool RemoveKey( KEY key );
	void RemoveAll();

	CMap();
	virtual ~CMap();
};

#endif // !defined(AFX_MAP_H__C9D3DD12_F648_4D8D_BD3A_E670D142C8E5__INCLUDED_)
