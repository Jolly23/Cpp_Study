// qsortbsearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <search.h>
#include <time.h>
#include <iostream>
using namespace std;
//��������������qsort����������bsearch���Һ�����
//��Ҫע����Ƿ���ֵ�����ͣ����á�ǿ��ת��.

struct DATA
{
	int nNumb;
	char sName[20];
	double fMath;
}	D[3] = {0};

int compare(const void * a, const void * b)
{
	return ( ((DATA*)a)->nNumb - ((DATA*)b)->nNumb );
}

void main()
{
	DATA D[3] = {
		{2015,"chaaf",89.5},
		{3245,"awdaf",31.2},
		{1245,"214af",59.5}
	};
	qsort(&D,3,sizeof(D[0]),compare);

	int  i = 0 ;

	while(i < 3)
	{
		cout << "����:" << D[i].sName << endl;
		cout << "ѧ��:" << D[i].nNumb << endl << endl;
		++i;
	}
	int nSearch = 2015;
//	cout << "������Ҫ���ҵ�ѧ�ţ�" ;
//	cin  >> nSearch;
	int *p = (int*)bsearch(&nSearch,&D->nNumb,3,sizeof(D[0]),compare);
	cout << *p << endl;
	system("pause");
}
