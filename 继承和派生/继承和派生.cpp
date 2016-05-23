// 继承和派生.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//Struct/Class 派生类名 ：[继承方式] 基类名

struct STUD			
{
	STUD()
	{
		cout << "STUD构造函数" << endl;
	}
	~STUD()
	{
		cout << "~STUD析构函数" << endl;
	}
	int nNumb;
	char sName[20];
	char Sex;
};

struct SArt : public STUD	//派生
{
	SArt()
	{
		cout << "SArt构造函数" << endl;
	}
	~SArt()
	{
		cout << "~SArt析构函数" << endl;
	}

	double lfHistory;
	double lfZhengzhi;
	double lfDili;
};

struct SScn : private STUD	//派生
{
	double lfWuli;
	double lfHuaxue;
	double lfShengwu;
	double lfSum;
	void Input()
	{
		cout << "输入性别:" ;
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
