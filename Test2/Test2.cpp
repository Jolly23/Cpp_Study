// Test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <conio.h>
#include <iostream>
using namespace std;
vector<int> list;
vector<int> YuShu0;
vector<int> YuShu1;
vector<int> YuShu2;

void Print();
void Print(int nSel);


void main()
{
	int ListNewNumb ;
	do{
		cout << "������һ�����֣���ӵ�����(����0ֹͣ����)��" ;
		cin  >> ListNewNumb ;
		if(ListNewNumb)
			list.push_back(ListNewNumb);
		else
			break;
	}while(true);
	int i = 0;
	int GrossListMember = list.size();
	while(i < GrossListMember)
	{
		if(list[i] % 3 == 0)
			YuShu0.push_back(list[i]);
		if(list[i] % 3 == 1)
			YuShu1.push_back(list[i]);
		if(list[i] % 3 == 2)
			YuShu2.push_back(list[i]);
		++i;
	}
	do{
		system("cls");
		Print();
	}while(true);
}

void Print()
{
	char cSel;
	cout << "��ѡ��Ҫ��ӡ��������У�" << endl
		 << "1.ԭ����" << endl
		 << "2.����Ϊ0������" << endl
		 << "3.����Ϊ1������" << endl
		 << "4.����Ϊ2������" << endl
		 << "0.�˳�" << endl;
	cSel = getch();
	switch(cSel)
	{
	case '1':
		Print(1);
		break;
	case '2':
		Print(2);
		break;
	case '3':
		Print(3);
		break;
	case '4':
		Print(4);
		break;
	case '0':
		_exit(0);
		break;
	default:
		cout << "ѡ�����������ѡ��" << endl;
		Print();
		break;
	}
}

void Print(int nSel)
{
	int Gross, i;
	if(nSel == 1)
	{
		i = 0;
		Gross = list.size();
		while(i < Gross)
		{
			cout << list[i] << endl;
			++i;
		}
	}

	if(nSel == 2)
	{
		i = 0;
		Gross = YuShu0.size();
		while(i < Gross)
		{
			cout << YuShu0[i] << endl;
			++i;
		}
	}

	if(nSel == 3)
	{
		i = 0;
		Gross = YuShu1.size();
		while(i < Gross)
		{
			cout << YuShu1[i] << endl;
			++i;
		}
	}

	if(nSel == 4)
	{
		i = 0;
		Gross = YuShu2.size();
		while(i < Gross)
		{
			cout << YuShu2[i] << endl;
			++i;
		}
	}
	system("pause");
}