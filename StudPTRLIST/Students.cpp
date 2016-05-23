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
	SStud *p = NULL;
	cout << "请选择 1.文科 - 2.理科" << endl;
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
		p = (SStud*)list[i];
		int nType = list[i]->GetType();
		fwrite(&nType,1,sizeof(int),fp);
		fwrite(p,1,p->GetSize(),fp);
		++i;
	}
	fclose(fp);
}

void CStudents::Load()
{
	FILE *fp = fopen("./stud.lv","rb");
	if(!fp)
		return;
	int nRes = 0;
	int nType;
	SStud *p = NULL;
	while(true)
	{
		nRes = fread(&nType,1,sizeof(int),fp);
		if(nRes <= 0)
			break;
		if(nType == 1)
		{
			SScn s;
			p = new SScn;
			fread(&s,1,p->GetSize(),fp);
			*((SScn*)p)=s;
		}
		if(nType == 2)
		{
			SArt s;
			p = new SArt;
			fread(&s,1,p->GetSize(),fp);
			*((SArt*)p)=s;
		}
		list.push_back(p);
	}
	fclose(fp);	
}
