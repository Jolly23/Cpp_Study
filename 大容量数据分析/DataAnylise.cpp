// DataAnylise.cpp: implementation of the CDataAnylise class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DataAnylise.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataAnylise::CDataAnylise()
{
	Times = 0	;	//总猜数次数
	OldTimes= 0	;	//记录上次猜数次数
	Success = 0	;	//总完成样本数
	OSTimes = 1	;	//样本序号记录
	TimesMin= INT_MAX ;	//最小猜中所用次数
	TimesMax= 0 ;	//最大猜中所用次数
	TimesOne= 0 ;	//单样本猜中结果所用猜测次数
}

CDataAnylise::~CDataAnylise()
{
	delete []MinMax;
}

void CDataAnylise::OSMain()
{
	Times   = 0;
	OldTimes= 0;
	Success = 0;
	OSTimes = 1;
	TimesMin= INT_MAX ;
	TimesMax= 0 ;
	TimesOne= 0 ;


	fflush;
	cout << "请输入猜数范围跨度(0退出)：" ;
	cin  >> Width;
	if(Width <= 0)
	{
		if(Width == 0)
			_exit(1);
		cout << "输入有误，随机数跨度不可以小于 0 " << endl;
		system("pause");
		return;
	}
	
	fflush;
	cout << "请输入 数据分析 总样本数：" ;
	cin  >> OSMax ;
	if(OSMax == 0)
	{
		cout << "输入有误，样本数必须大于 0 " << endl;
		system("pause");
		return;
	}
	
	fflush;
    cout << "请 选择 猜数字 取数 模式：" << endl;
	cout << "1：范围内随机取数模式"  << endl;
	cout << "2：范围内取中间数模式"  << endl;
	MSel = getch();
	
	switch(MSel)
	{
	case '1':
		MSel = 'A' ;
		break;
	case '2':
		MSel = 'B' ;
		break;
	default:
		cout << "选择错误！" << endl;
		system("pause");
		return;
	}
	unsigned long TimeBegin = GetTickCount();
	do{
		OS();
	}while(Success < OSMax);
	unsigned long TimeEnd   = GetTickCount();
	
	
	if(MSel == 'A'  ||  MSel == 'B')
	{
		cout << endl;
		cout << "**********分析结果***********"<< endl;
		if(MSel == 'A')
			cout << "取数模式：范围内随机取数模式" << endl;
		if(MSel == 'B')
			cout << "取数模式：范围内取中间数模式" << endl;
		cout << "计算机分析总样本数 = " << OSMax << endl;
		cout << "单样本猜数数据跨度 = " << Width << endl;
		cout << "计算机猜数总次数 = " << Times << endl;
		cout << "平均每次成功所需猜测次数 = " << (double)Times / (double)Success << endl;
		cout << "最大单次样本分析猜测次数 = " << TimesMax << endl;
		cout << "最小单次样本分析猜测次数 = " << TimesMin << endl;
		cout << "*****************************"<< endl;
		cout << "计算机共运算了 " << (double)(TimeEnd - TimeBegin) / 1000 << " 秒" << endl;
		cout << "天津科技数据分析中心 V 1.0" << endl;
		cout << "\tDesigned By ZhaoLei" << endl;
		cout << "*****************************"<< endl;
	}
	system("pause");
}

void CDataAnylise::OS()
{
	cout << "正在进行第 " << OSTimes << " 次样本运算: " ;
	MinMax[0] = -1;
	MinMax[1] = Width;
	bool TorF;
	unsigned int ComputerNumb = RandNumb();
	unsigned int ComputerGuess;
	OldTimes = Times;
	do{
		ComputerGuess = RandNumb(MinMax[0],MinMax[1]);
		TorF = Compare(ComputerNumb,ComputerGuess);
	}while(TorF == false);
	TimesOne = Times - OldTimes ;
	cout << "\t\t" << TimesOne << "\t次猜出随机数" << endl;
	if( TimesOne < TimesMin)
		TimesMin = TimesOne;
	if( TimesOne > TimesMax)
		TimesMax = TimesOne;
	++OSTimes;
}

bool CDataAnylise::Compare(int ComputerNumb, int ComputerGuess)
{
	if(ComputerGuess > ComputerNumb)
	{
		MinMax[1] = ComputerGuess;
		++Times;
		return false;
	}
	
	if(ComputerGuess < ComputerNumb)
	{
		MinMax[0] = ComputerGuess;
		++Times;
		return false;
	}
	if(ComputerGuess == ComputerNumb)
	{
		++Times;
		++Success;
		return true;
	}
}

int CDataAnylise::RandNumb()
{
	unsigned int GameNumb = rand() % Width ;
	return GameNumb;
}

int CDataAnylise::RandNumb(int Min,int Max)
{
	unsigned int GameNumb;
	if(MSel == 'A')
		GameNumb = rand() % (Max - Min - 1) + 1 + Min;
	if(MSel == 'B')
		GameNumb = (Max+Min) / 2;
	return GameNumb;
}

