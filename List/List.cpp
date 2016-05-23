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
	cout << "1.�������" << endl
		 << "2.�������" << endl
		 << "3.ɾ������" << endl
		 << "0.�˳�"	 << endl;
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
	cout <<	"������������" ;
	cin  >> pNew ->sName;
	cout << "������ѧ�ţ�" ;
	cin  >> pNew ->nNumb;
	cout << "������ɼ���" ;
	cin  >> pNew ->fMath;
	g_list.push_back(*pNew);
}
void Print()
{
	system("cls");
	cout << "���� " << g_list.size() << " ������" << endl;
	cout << "����\tѧ��\t�ɼ�" << endl;
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
	cout << "������Ҫɾ��������������";
	cin  >> MOD.sName;

	list<STUD>::iterator it = g_list.begin();
	while(it != g_list.begin()  &&  strcmp(it ->sName,MOD.sName) != 0)
		++it;
	if( strcmp(it ->sName,MOD.sName) == 0 )
		g_list.erase(it);
}

//erase ���ܣ�ɾ������������������ɾ���м�ڵ㣬����һ������ɾ���˽ڵ㣩
//Remove����ͬ�ϣ����������ݣ����ǽڵ�