// Students.h: interface for the CStudents class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTS_H__B178F362_3E42_440E_AA8A_D916DE65C07E__INCLUDED_)
#define AFX_STUDENTS_H__B178F362_3E42_440E_AA8A_D916DE65C07E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
using namespace std;

struct SStud
{
	int nNumb;
	char sName[20];
	virtual void Input()
	{
		cout << "������ѧ��/����: ";
		cin  >> nNumb >> sName;
	}
	virtual void Print()
	{
		cout << "ѧ�ţ�" << nNumb << "\t������" << sName ;
	}
	virtual int GetSize()
	{
		return sizeof(*this);
	}
	virtual int GetType()
	{
		return 0;
	}
	virtual void Save(FILE *fp) = 0;
	virtual void Load(FILE *fp) = 0;
};	

struct SScn : public SStud
{
	float fWuli,fHuaxue;
	virtual void Input()
	{
		SStud::Input();
		cout << "����������ɼ�/��ѧ�ɼ�: ";
		cin  >> fWuli >> fHuaxue;
	}
	virtual void Print()
	{
		SStud::Print();
		cout << "\t����" << fWuli << "\t��ѧ��" << fHuaxue << endl;
	}
	virtual int GetSize()
	{
		return sizeof(*this);
	}
	virtual int GetType()
	{
		return 1;
	}
	virtual void Save(FILE *fp)
	{
		fwrite(&nNumb,1,sizeof(*this)-4,fp);	
	}
	virtual void Load(FILE *fp)
	{
		fread(&nNumb,1,sizeof(*this)-4,fp);	
	}
};

struct SArt : public SStud
{
	float fLishi;
	virtual void Input()
	{
		SStud::Input();
		cout << "��������ʷ�ɼ�: ";
		cin  >> fLishi;
	}
	virtual void Print()
	{
		SStud::Print();
		cout << "\t��ʷ��" << fLishi << endl;
	}
	virtual int GetSize()
	{
		return sizeof(*this);
	}
	virtual int GetType()
	{
		return 2;
	}
	virtual void Save(FILE *fp)
	{
		fwrite(&nNumb,1,sizeof(*this)-4,fp);	
	}
	virtual void Load(FILE *fp)
	{
		fread(&nNumb,1,sizeof(*this)-4,fp);	
	}
};

class CStudents  
{
public:
	void Load();
	void Save();
	void Print();
	void Input();
	int Menu();
	CStudents();
	virtual ~CStudents();
};

#endif // !defined(AFX_STUDENTS_H__B178F362_3E42_440E_AA8A_D916DE65C07E__INCLUDED_)
