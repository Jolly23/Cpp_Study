// Students.h: interface for the CStudents class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTS_H__17A95F70_36EE_493B_A538_32B16BDB5C20__INCLUDED_)
#define AFX_STUDENTS_H__17A95F70_36EE_493B_A538_32B16BDB5C20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include "SockJolly.h"

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
	BOOL CheckOneNumb(SockJolly *pSocka);
	static CStudents st;
	BOOL OnReceive(SockJolly *pSocka);
	void Start();
	CStudents();
	virtual ~CStudents();
	BOOL ModifyData(SockJolly *pSocka);
	void Load();
	void Save();
	BOOL DeleteOne(SockJolly *pSocka);
	std::vector<Stud> m_list;
	SockJolly m_sock;
	BOOL SendAllData(SockJolly *pSocka);
	BOOL AddStud(SockJolly *pSocka);
	BOOL SendOneData(SockJolly *pSocka);
};

#endif // !defined(AFX_STUDENTS_H__17A95F70_36EE_493B_A538_32B16BDB5C20__INCLUDED_)
