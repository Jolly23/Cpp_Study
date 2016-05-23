// GameGuessNumb.cpp : Defines the entry point for the console application.
//

//�߼��������

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

struct UserData
{
	int SumGameTimes;
	int SumSteps;
	int SumFaultTimes;
}   g_UserData;

int  RandNumb();
void Game();
int  GameOS();
void SaveUserData();
void LoadUserData();
void UserAnalysis();

void main()
{
	Game();
	UserAnalysis();
	system("pause");
}

int RandNumb()
{
	srand( (unsigned)time( NULL ) );
	int GameNumb = rand() % 100 + 1;
	return GameNumb;
}

int GameOS()
{
	int RandN = RandNumb();
	int UserGuess;
	int Times = 0;
	int FaultTimes = 0;
	int Min = 0, Max = 100;
	cout << "��Ϸ�� ��1~100�³�һ������� ��" << endl;
	cout << endl;
	do
	{
		cout << "��������µ�����" ;
		cin  >> UserGuess;
		if(UserGuess <= Min || UserGuess > Max )
		{
			cout << "�����������Χ���������� " << Min << " ~ " << Max << " ֮�� " << endl;
			cout << endl;
			FaultTimes++;
			continue;
		}

		if(UserGuess > RandN)
		{
			cout << "��Ԥ�����ִ�" << endl;
			cout << endl;
			if(UserGuess < Max)
				Max = UserGuess ; 
			Times++;
		}
		if(UserGuess < RandN)
		{
			cout << "��Ԥ������С��" << endl;
			cout << endl;
			if(UserGuess > Min)
				Min = UserGuess ; 
			Times++;
		}
		if(UserGuess == RandN)
		{
			Times++;
			break;
		}
	}while(true);

	LoadUserData();
	g_UserData.SumSteps      += Times;
	g_UserData.SumFaultTimes += FaultTimes;
	g_UserData.SumGameTimes++;
	SaveUserData();

	return Times;
}

void Game()
{	
	char Sel;
	do
	{
		system("cls");
		cout << "��ʼ��Ϸ�ɣ�" << endl;
		int Times = GameOS();
		cout << "��Ϸ���� �� �������� " << Times << " �ξͲ�������ȷ�𰸣�" << endl;
		cout << "��Ҫ����һ���𣿡���Y����һ�֡�" << endl;
		Sel = getch();
	}while(Sel == 'y' || Sel == 'Y');
}

void UserAnalysis()
{
	system("cls");
	LoadUserData();
	cout << "*************************" << endl;
	cout << "�� �� �� ��  ���ݷ�������" << endl;
	cout << "*************************" << endl;
	cout << endl;
	cout << "�� �� ���й� " << g_UserData.SumGameTimes << " ����Ϸ" << endl;
	cout << endl;
	cout << "�ۼƲ������� " << g_UserData.SumSteps << " ��" << endl;
	cout << endl;
	cout << "�ۼ�ʧ����� " << g_UserData.SumFaultTimes << " ��" << endl;	
	cout << endl;
	cout << "ƽ�� " <<	(float)g_UserData.SumSteps /  (float)g_UserData.SumGameTimes << " �μ��ɲ³������" <<endl;
	cout << endl;
	cout << "ƽ��ʧ����� " << (float)g_UserData.SumFaultTimes /  (float)g_UserData.SumGameTimes<< " ��" << endl;
	cout << endl;
}

void SaveUserData()
{
	FILE *fp = fopen("DATA.lqm","w");
	
	fwrite(&g_UserData,1,sizeof(UserData),fp);
		
	fclose(fp);
}

void LoadUserData()
{
	FILE *fp = fopen("DATA.lqm","a+");
	
	fread(&g_UserData,1,sizeof(UserData),fp);
		
	fclose(fp);
}