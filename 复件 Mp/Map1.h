// Map1.h: interface for the CMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP1_H__A862DCD7_DF0F_456F_80D8_278D0CBF1055__INCLUDED_)
#define AFX_MAP1_H__A862DCD7_DF0F_456F_80D8_278D0CBF1055__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdio.h>
struct Stud
{
	int nNumb;
	char sName[20];
};

typedef int KEY;
typedef Stud VALUE;

struct SNode
{
	VALUE value;
	KEY key;
	SNode *pL,*pR;
	SNode(VALUE invalue)
	{
		key = invalue.nNumb;
		value = invalue;
		pL = pR = NULL;
	}
	SNode(KEY inkey)
	{
		key = inkey;
		pL = pR = NULL;
	}
};

class CMap  
{//作业中要求根据构造函数指定的HashSize在堆上申请指针数组
	SNode *m_pRoot;
public:
	void PrintAll(SNode* pNode);
	void PrintAll();
	void SetAt(VALUE value);
	void SetAt(SNode *&pNode,KEY key,VALUE value);
	bool LookUp(SNode *pNode,KEY key,VALUE& rValue);
	bool LookUp(KEY inkey,VALUE& rValue);

	VALUE& operator[](KEY inkey);
	VALUE& GetValue(SNode *pNode, KEY inkey);
	bool RemoveKey( KEY key );
	void RemoveAll();
	void RemoveAll(SNode *pNode);


	CMap();
	~CMap();
};

#endif // !defined(AFX_MAP1_H__A862DCD7_DF0F_456F_80D8_278D0CBF1055__INCLUDED_)
