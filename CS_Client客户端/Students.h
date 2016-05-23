// Students.h: interface for the CStudents class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTS_H__3F9ACB75_9C1C_4783_AA00_A062CD1D465A__INCLUDED_)
#define AFX_STUDENTS_H__3F9ACB75_9C1C_4783_AA00_A062CD1D465A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "stdafx.h"

enum REQ
{
	REQ_ADD = 50091,
	REQ_DELALL,
	REQ_DELONE,
	REQ_MOD,
	REQ_FINDBYNUMB,
	REQ_BROW,
	REQ_BROWONE,
	REQ_CNUMB
};

struct Stud
{
	int nNumb;
	char sName[20];
	char sSex[4];
};

class CStudents  
{
public:
	bool Print(int nPNumb);
	void Delete();
	void Input();
	const int ServerPort;
	BOOL CheckNumb(int CNumb);
	void Print();
	int Menu();
	void Start();
	void SortBy(int nSel);
	int PrintMenu();
	void Modify();
	void FindData();
	CStudents();
	~CStudents();
};

#endif // !defined(AFX_STUDENTS_H__3F9ACB75_9C1C_4783_AA00_A062CD1D465A__INCLUDED_)
