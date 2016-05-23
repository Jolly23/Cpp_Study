// Stud.h: interface for the CStud class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUD_H__063F6633_BB4E_439E_8D60_D8CD657387DD__INCLUDED_)
#define AFX_STUD_H__063F6633_BB4E_439E_8D60_D8CD657387DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>

using namespace std;

struct SNode
{
	int data;
	SNode *pNext;
};


class CStud  
{
public:
	CStud();
	virtual ~CStud();

	int GetCount();	
	void AddHead(int d);
};

#endif // !defined(AFX_STUD_H__063F6633_BB4E_439E_8D60_D8CD657387DD__INCLUDED_)
