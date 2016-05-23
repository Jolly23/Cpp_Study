// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <process.h>
#include <list>
using namespace std;

struct STUD
{
	int    nNumb;
	double fMath;
	char   sName[20];
};
list<STUD> g_list;

void Menu();
void Input();
void Print();
void Rom();

void main()
{
	do{
		Menu();
	}while(true);
}

void Menu()
{
	system("cls");
	cout << "**********" << endl;
	cout << "1.添加数据" << endl
		 << "2.浏览数据" << endl
		 << "3.删除数据" << endl
		 << "0.退出"	 << endl;
	cout << "**********" << endl;
	char cSel;
	cSel = getch();
	switch(cSel)
	{
	case '1':
		Input();
		break;
	case '2':
		Print();
		system("pause");
		break;
	case '3':
		Rom();
		break;

	case '0':
		exit(1);
	}
}

void Input()
{
	system("cls");
	STUD *pNew = new STUD;
	cout <<	"请输入姓名：" ;
	cin  >> pNew ->sName;
	cout << "请输入学号：" ;
	cin  >> pNew ->nNumb;
	cout << "请输入成绩：" ;
	cin  >> pNew ->fMath;
	g_list.push_back(*pNew);
}
void Print()
{
	system("cls");
	cout << "共有 " << g_list.size() << " 条数据" << endl;
	cout << "姓名\t学号\t成绩" << endl;
	list<STUD>::iterator it = g_list.begin();
	while(it != g_list.end())
	{
		cout  << it ->sName << '\t'
			  << it ->nNumb << '\t'
			  << it ->fMath << endl;	
		++it;
	}
}

void Rom()
{
	STUD *p = new STUD;
	STUD MOD;
	cout << "请输入要删除的数据姓名：";
	cin  >> MOD.sName;

	list<STUD>::iterator it = g_list.begin();
	while(it != g_list.begin()  &&  strcmp(it ->sName,MOD.sName) != 0)
		++it;
	if( strcmp(it ->sName,MOD.sName) == 0 )
		g_list.erase(it);
}

//erase 功能：删除（带入两个参数则删除中间节点，带入一个参数删除此节点）
//Remove功能同上，但带入数据，并非节点