// �̳к�����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//Struct/Class �������� ��[�̳з�ʽ] ������

struct STUD			
{
	STUD()
	{
		cout << "STUD���캯��" << endl;
	}
	~STUD()
	{
		cout << "~STUD��������" << endl;
	}
	int nNumb;
	char sName[20];
	char Sex;
};

struct SArt : public STUD	//����
{
	SArt()
	{
		cout << "SArt���캯��" << endl;
	}
	~SArt()
	{
		cout << "~SArt��������" << endl;
	}

	double lfHistory;
	double lfZhengzhi;
	double lfDili;
};

struct SScn : private STUD	//����
{
	double lfWuli;
	double lfHuaxue;
	double lfShengwu;
	double lfSum;
	void Input()
	{
		cout << "�����Ա�:" ;
		cin  >> Sex;
	}
};

int main(int argc, char* argv[])
{
//	SScn zl;
	SArt yx;
//	zl.Input();
	return 0;
}
