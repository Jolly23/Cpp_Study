// game.cpp : Defines the entry point for the console application.
//


//�����������

#include "stdafx.h"
#include <process.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

int RandNumb();
void Game();
int GameOS();

void main()
{
	Game();
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
	cout << "��Ϸ����1~100�³�һ���������" << endl;
	do
	{
		cout << "��������µ�����" ;
		cin  >> UserGuess;
		if(UserGuess <= 0 || UserGuess >100 )
		{
			cout << "�������Χ��1~100 " << endl;
			continue;
		}

		if(UserGuess > RandN)
		{
			cout << "��Ԥ�����ִ�" << endl;
			Times++;
		}
		if(UserGuess < RandN)
		{
			cout << "��Ԥ������С��" << endl;
			Times++;
		}
		if(UserGuess == RandN)
			break;
	}while(true);
	return Times;
}

void Game()
{
	system("cls");
	char Sel;
	do
	{
		cout << "��ʼ��Ϸ�ɣ�" << endl;
		int Times = GameOS();
		cout << "��Ϸ���� �� �������� " << Times << " �ξͲ�������ȷ�𰸣�" << endl;
		cout << "��Ҫ����һ���𣿡���Y����һ�֡�" << endl;
		Sel = getch();
	}while(Sel == 'y' || Sel == 'Y');
}