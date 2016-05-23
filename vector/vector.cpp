// vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

struct DATA
{
	int nNumb;
	char sName[20];
	double dlSala;
};

void operator<< (ostream &cout,DATA &d)
{
	cout << d.nNumb << "\t" << d.sName  << "\t" << d.dlSala   << endl;
	//想要的输出方式；
}

void main()
{
	vector<DATA> vt;
	DATA user[5] =
	{
		{1001,"zl",18600}	,
		{1002,"yx",8000}	,
		{1003,"dbq",3000}	,
		{1004,"llf",3000}	,
		{1005,"lzg",5000}
	};
	int i = 0, j = 0, nSize = vt.size();

	while (j < 5)
		vt.push_back(user[j++]);

	nSize = vt.size();
	cout << "总数是：" << nSize << endl;

	while(i < nSize)
		cout << vt[i++] ;

	system("pause");
}
