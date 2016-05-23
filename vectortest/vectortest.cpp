// vectortest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>
using std::cout;

void ZLMenu();
void ZLOS_1();
void ZLOS_2();
void ZLOS_3();
void ZLOS_4();
void ZLOS_5();
void ZLOS_6();
void ZLOS_7();

struct DATA
{
	int nNumb;
	char sName[20];
	double dMath;
};

std::vector<DATA> v_data;
std::vector<DATA>::iterator it;
int Max = 0;

void main()
{
	DATA *p = new DATA;
	int i = 0;
	p->nNumb = 2014;
	strcpy(p->sName,"ZhaoL");
	p->dMath = 92.3145;
	srand( (unsigned) time ( NULL ) );

    Max = rand() % 100 + 1 ;
	while(i < Max)
	{
		v_data.push_back(*p);
		++i;
	}
	delete p;
	do{
		ZLMenu();
	}while(true);
	system("pause");
}

void ZLMenu()
{
	char cSel;
	cout << "*******************" << std::endl;
	cout << "1.v_data头指针地址" << std::endl
		 << "2.v_data尾指针地址" << std::endl
		 << "3.显示数据数量"	 << std::endl
		 << "4.展示所有数据"	 << std::endl
		 << "5.vector当前数据容量" << std::endl
		 << "6.测试数据"		 << std::endl
		 << "7.删除数据"		<< std::endl;
	cSel = getch();
	switch(cSel)
	{
	case '1':
		ZLOS_1();
		break;
	case '2':
		ZLOS_2();
		break;
	case '3':
		ZLOS_3();
		break;
	case '4':
		ZLOS_4();
		break;
	case '5':
		ZLOS_5();
		break;
	case '6':
		ZLOS_6();
		break;
	case '7':
		ZLOS_7();
		break;
	case '0':
		_exit(1);
	default:
		return;
	}
}

void ZLOS_1()
{
	cout << "v_data头指针地址:" << v_data.begin() << std::endl << std::endl;
	cout << it << std::endl;
}

void ZLOS_2()
{
	cout << "v_data尾指针地址:" << v_data.end() << std::endl << std::endl;
}

void ZLOS_3()
{
	cout << "显示数据数量 = " << v_data.size() << std::endl ;
	cout << "实 际 数据量 = " << Max << std::endl ;
	if( v_data.size() == Max )
		cout << "验证成功！" << std::endl << std::endl;
}

void ZLOS_4()
{
	DATA *p = v_data.begin();
	DATA *pd= v_data.end();
	cout << "学号\t姓名\t成绩" << std::endl;
	while(p != pd)
	{
		cout << Max - (pd - p) + 1 << ": " << p->nNumb << "\t" << p->sName << "\t" << p->dMath << std::endl;
		++p;
	}
}

void ZLOS_5()
{
	cout << "vector当前数据容量 = " << v_data.capacity() << std::endl;
}

void ZLOS_6()
{
	DATA *p = new DATA[5];
	int i = 0;
	while(i < 5)
	{
		(p+i)->nNumb = 0000;
		strcpy((p+i)->sName,"TEST");
		(p+i)->dMath = 00.00;
		++i;
	}
	it = v_data.begin();
	v_data.insert(it,p,p+5);
	delete []p;
}

void ZLOS_7()
{
	int i ;
	cout << "请输入要删除的数据序号：" ;
	std::cin  >> i;
	it = v_data.begin();
	v_data.erase(it+i);
}
sort