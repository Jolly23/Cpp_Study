// Students.cpp: implementation of the CStudents class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Students.h"
#include <vector>
#include <conio.h>
#include <iostream>
using namespace std;
vector<SStud*> list;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudents::CStudents()
{
	this->Load();
}

CStudents::~CStudents()
{
	this->Save();
}

SStud *CreateInstance(int nType)
{
	SStud *p = NULL;
	if(nType == 1)
		p = new SScn;
	if(nType == 2)
		p = new SArt;
	return p;
}

int CStudents::Menu()
{
	cout << "1.添加数据" << endl
		 << "2.浏览数据" << endl
		 << "0.退出" << endl;
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
	return 1;
}

void CStudents::Input()
{
	cout << "请选择 1.文科 - 2.理科" << endl;
	char cSel = getch();
	SStud *p = CreateInstance((cSel == '1'? 1: 2));
	if(p)
	{
		p->Input();
		list.push_back(p);
	}
}

void CStudents::Print()
{
	int nCount = list.size();
	int i = 0;
	while(i < nCount)
	{
		list[i]->Print();
		++i;
	}
}

void CStudents::Save()
{
	FILE *fp = fopen("./stud.lv","wb");
	if(!fp)
	{
		cout << "保存文件时失败！" << endl;
		return;
	}
	SStud *p;
	int nCount = list.size();
	int i = 0;
	while(i < nCount)
	{
		p = list[i];
		int nType = p->GetType();
		fwrite(&nType,1,sizeof(int),fp);
		p->Save(fp);
		++i;
	}
	fclose(fp);
}

void CStudents::Load()
{
	FILE *fp = fopen("./stud.lv","rb");
	if(!fp)
		return;
	int nType;
	SStud *p;
	while(true)
	{
		if( fread(&nType,1,sizeof(int),fp) <= 0 )
			break;
		p = CreateInstance(nType);
		if(p)
		{
			p->Load(fp);
			list.push_back(p);
		}
	}
	fclose(fp);	
}
