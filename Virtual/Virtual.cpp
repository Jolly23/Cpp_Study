// Virtual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <list>
using namespace std;
struct SStud
{
	char sName[20];
	int nNumb;
	virtual void Print()
	{
		//cout << "�����麯����" << endl;
	}
	virtual void Input()
	{
	
	}
};
list<SStud*> g_list;

struct SArt : public SStud
{
	float fPolitcal;
	float fHistory;
	void Print()
	{
		cout << "����=" << fPolitcal << "\t" << "��ʷ=" << fHistory << endl;
	}
	void Input()
	{
		cout << "�������ĿƳɼ������� ��ʷ����";
		cin  >> fPolitcal >> fHistory ;
	}
};
struct SScn : public SStud
{
	float fMath;
	float fPhysical;
	float fChemcal;
	void Print()
	{
		cout << "��ѧ=" << fMath << "\t" << "����=" << fPhysical<< "\t" << "��ѧ=" << fChemcal << endl;
	}
	void Input()
	{
		cout << "��������Ƴɼ�����ѧ ���� ��ѧ����";
		cin  >> fMath >> fPhysical >> fChemcal ;
	}
};

void Print()
{
	list<SStud*>::iterator it = g_list.begin();
	while(it != g_list.end())
	{
		SStud *p = *it++;
		p->Print();
	}
}

void Input()
{
	SStud *p = NULL;
	cout << "��ѡ���Ŀ���ƣ�1-2����" << endl;;
	char cSel = getch();
	switch(cSel)
	{
	case '1':
		p = new SArt;
		break;
	case '2':
		p = new SScn;
		break;
	};
	if(p)
	{
		p->Input();
		g_list.push_back(p);
		Print();
	}
}


int  Menu()
{
	cout << endl << endl <<"1.�����Ϣ" << endl
		 << "2.�鿴��Ϣ" << endl
		 << "0.�˳�"     << endl;
	char cSel = getch();
	switch(cSel)
	{
	case '1':
		Input();
		return 1;
	case '2':
		Print();
		return 1;
	case '0':
		return 0;
	};
}

int main(int argc, char* argv[])
{
	while( Menu() );
	return 0;
}
