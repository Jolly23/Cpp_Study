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
	Times = 0	;	//�ܲ�������
	OldTimes= 0	;	//��¼�ϴβ�������
	Success = 0	;	//�����������
	OSTimes = 1	;	//������ż�¼
	TimesMin= INT_MAX ;	//��С�������ô���
	TimesMax= 0 ;	//���������ô���
	TimesOne= 0 ;	//���������н�����ò²����
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
	cout << "�����������Χ���(0�˳�)��" ;
	cin  >> Width;
	if(Width <= 0)
	{
		if(Width == 0)
			_exit(1);
		cout << "���������������Ȳ�����С�� 0 " << endl;
		system("pause");
		return;
	}
	
	fflush;
	cout << "������ ���ݷ��� ����������" ;
	cin  >> OSMax ;
	if(OSMax == 0)
	{
		cout << "��������������������� 0 " << endl;
		system("pause");
		return;
	}
	
	fflush;
    cout << "�� ѡ�� ������ ȡ�� ģʽ��" << endl;
	cout << "1����Χ�����ȡ��ģʽ"  << endl;
	cout << "2����Χ��ȡ�м���ģʽ"  << endl;
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
		cout << "ѡ�����" << endl;
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
		cout << "**********�������***********"<< endl;
		if(MSel == 'A')
			cout << "ȡ��ģʽ����Χ�����ȡ��ģʽ" << endl;
		if(MSel == 'B')
			cout << "ȡ��ģʽ����Χ��ȡ�м���ģʽ" << endl;
		cout << "����������������� = " << OSMax << endl;
		cout << "�������������ݿ�� = " << Width << endl;
		cout << "����������ܴ��� = " << Times << endl;
		cout << "ƽ��ÿ�γɹ�����²���� = " << (double)Times / (double)Success << endl;
		cout << "��󵥴����������²���� = " << TimesMax << endl;
		cout << "��С�������������²���� = " << TimesMin << endl;
		cout << "*****************************"<< endl;
		cout << "������������� " << (double)(TimeEnd - TimeBegin) / 1000 << " ��" << endl;
		cout << "���Ƽ����ݷ������� V 1.0" << endl;
		cout << "\tDesigned By ZhaoLei" << endl;
		cout << "*****************************"<< endl;
	}
	system("pause");
}

void CDataAnylise::OS()
{
	cout << "���ڽ��е� " << OSTimes << " ����������: " ;
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
	cout << "\t\t" << TimesOne << "\t�β³������" << endl;
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

