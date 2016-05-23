// Exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int *p = new int[300];

int  InPut();
void Sort(int &p,int nSize);

void main()
{
	int nSize = InPut();
	Sort(*p,nSize);
}

int InPut()
{
	char Char[300];
	int *p = new int[300];
	int  i = 0;
	cout << "请输入一组数据（输入x停止录入）：" ;
	while(true)
	{
		cin >> Char[i];
		if( isdigit(Char[i]) == 0 )
			break;
		p[i] = atoi(&Char[i]);
		cout << "已存入！" << endl;
		++i;
	}
	return i;
}

void Sort(int &p,int nSize)
{
	int i = 0, j = 0;
	int Int[300];
	memcpy(&Int,&p,sizeof(int)*nSize);

	while(i < nSize)
	{
		j = 0;
		while(j < nSize - i)
		{
			if(Int[j] > Int[j+1])
			{
				int t = Int[j];
				Int[j+1] = Int[j];
				Int[j] = t;
			}
			++j;
		}
		++i;
	}
	
	cout << "共有 " << nSize << " 条数据"  << endl;
	int o = 0;
	while(o < nSize)
	{
		cout << Int[o] << endl;
		++o;
	}
}