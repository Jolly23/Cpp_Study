// Student.h: interface for the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__EB8A772B_B8D9_4DA3_9B85_1A0A67A55466__INCLUDED_)
#define AFX_STUDENT_H__EB8A772B_B8D9_4DA3_9B85_1A0A67A55466__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

typedef struct SInfo
{
	int nNumb;
	char sName[20];
	float fSala;
}DATA;

class CStudent  
{
private:
	CArray<DATA,DATA> m_arr;
	void ModifySalary(int position);
	void ModifyNumb(int position);
	void ModifyName(int position);
	void ModifyOS(int position);
	void ModifyMenu();
	void Print(int Numb);
	int  SearchByNumb();
	int  SearchByName();
	void SearchMenu();
	void Delete(int DNumb);
	void DeleteMenu();
	bool ChackNumb(int nNumb);
	void Insert();
	void Version();
	void Save();
	void SayByeToUser();
	void MenuDispose(char Select);
	void SortByWhat( int (*SortBy) (DATA *p1,DATA *p2) );
	char BrowseMenu();

	void Print();

public:
	CStudent();
	virtual ~CStudent();
	void Menu();
	void Load();
};

int SortByNumb(DATA *p1,DATA *p2);
int SortByName(DATA *p1,DATA *p2);
int SortBySalary(DATA *p1,DATA *p2);

#endif // !defined(AFX_STUDENT_H__EB8A772B_B8D9_4DA3_9B85_1A0A67A55466__INCLUDED_)
