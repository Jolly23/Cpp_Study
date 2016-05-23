// Test213.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

typedef struct Student
{
	int   nNumb;
	float fMath;
	char  sName[20];
} DATA;

void main()
{
	DATA *pNew = new DATA;
	memset(pNew,0,sizeof(pNew));

	pNew ->fMath = 99.5f;
	pNew ->nNumb = 2014;
	strcpy(pNew ->sName , "ZhaoLei");

	list<DATA> MyList1;
	MyList1.push_back(*pNew);

	list<DATA>::iterator it = MyList1.begin();
	cout << "MyList1.size() = " << MyList1.size() <<endl;
	cout << "ÐÕÃû\tÑ§ºÅ\t³É¼¨" << endl;
	while(it != MyList1.end())
	{
		cout  << it ->sName << '\t'
			  << it ->nNumb << '\t'
			  << it ->fMath << endl;	
		--it;
	}
	cout <<endl;
}
