// STATIC_TEST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CInfo
{
public:
	int   nNumb;
	char  sName[20];
	float fMath;
	float fAver;

	static int g_nCount;
	
	CInfo()
	{
		nNumb = 0;
		strcpy(sName,NULL);
		fMath = 0.0;
		fAver = 0.0;
	}
	CInfo(int Numb,float Math,float Aver,char Name[20])
	{
		this->nNumb = Numb;
		this->fMath = Math;
		this->fAver = Aver;
		strcpy(this->sName,Name);
	}
	
	void Print() const
	{
		cout << "学号\t姓名\t\t成绩\t平均\n";
		cout << this->nNumb << "\t" 
			 << this->sName << "\t\t" 
			 << this->fMath << "\t" 
			 << this->fAver << "\t" 
			 <<endl;
	}
};
int CInfo::g_nCount = 0;

void main()
{
	cout << CInfo::g_nCount <<endl;	
	CInfo test(1001,99.5,85,"ZhaoLei");
	test.Print();
	system("pause");
}
