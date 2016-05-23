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
		//cout << "这是虚函数！" << endl;
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
		cout << "政治=" << fPolitcal << "\t" << "历史=" << fHistory << endl;
	}
	void Input()
	{
		cout << "请输入文科成绩（政治 历史）：";
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
		cout << "数学=" << fMath << "\t" << "物理=" << fPhysical<< "\t" << "化学=" << fChemcal << endl;
	}
	void Input()
	{
		cout << "请输入理科成绩（数学 物理 化学）：";
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
	cout << "请选择文科理科（1-2）：" << endl;;
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
	cout << endl << endl <<"1.添加信息" << endl
		 << "2.查看信息" << endl
		 << "0.退出"     << endl;
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
