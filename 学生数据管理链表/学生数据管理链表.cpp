// 学生数据管理链表.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <malloc.h>

struct SSTU
{
	int   nNumb;
	char  sName[20];
	float fMath;
	SSTU *pNext;
} *g_pHead = NULL;


void Menu();
void Browse();
void Insert();
void Modify();
void Delete();


void main()
{
	Menu();
	system("pause");;
}


void Menu()
{
	int mode = 0;
	puts("************");
	puts("1.浏览数据");
	puts("2.添加数据");
	puts("3.修改数据");
	puts("4.删除数据");
	puts("5.退出程序");
	puts("************");
	printf("请选择：");
	scanf("%d",&mode);
	switch(mode)
	{
	case 1:
		Browse();
		break;
	case 2:
		Insert();
		break;
	case 3:
		Modify();
		break;
	case 4:
		Delete();
		break;
	case 5:
		return;
	}
}

void Browse()
{

}

void Insert()
{
	SSTU *p;

}

void Modify()
{

}

void Delete()
{

}