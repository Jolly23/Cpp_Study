// game.cpp : Defines the entry point for the console application.
//


//基础版猜数字

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
	cout << "游戏【从1~100猜出一个随机数】" << endl;
	do
	{
		cout << "请输入你猜的数：" ;
		cin  >> UserGuess;
		if(UserGuess <= 0 || UserGuess >100 )
		{
			cout << "随机数范围是1~100 " << endl;
			continue;
		}

		if(UserGuess > RandN)
		{
			cout << "比预设数字大！" << endl;
			Times++;
		}
		if(UserGuess < RandN)
		{
			cout << "比预设数字小！" << endl;
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
		cout << "开始游戏吧！" << endl;
		int Times = GameOS();
		cout << "游戏结束 ！ 您共猜了 " << Times << " 次就猜中了正确答案！" << endl;
		cout << "还要再来一局吗？【按Y再来一局】" << endl;
		Sel = getch();
	}while(Sel == 'y' || Sel == 'Y');
}